#include <iostream>
using namespace std;

// keyboard
char T[][6] = {
	{'A', 'B', 'C', 'D', 'E', 'F',},
	{'G', 'H', 'I', 'J', 'K', 'L',},
	{'M', 'N', 'O', 'P', 'Q', 'R',},
	{'S', 'T', 'U', 'V', 'W', 'X',},
	{'Y', 'Z', ' ', '-', '.', '\n',},
};

// find (x,y) of letter c in T
void find_letter(char c, int& x, int& y)
{
	x = -1;
	y = -1;
	for(int i = 0; i<5; i++){
		for(int j=0; j<6; j++){
			if(T[i][j] == c){
				x = j;
				y = i;
				break;
			}
		}
	}
}

int abs(int a)
{
	return a > 0 ? a : -a;
}
// count steps from start to end
int count_steps(char start, char end)
{
	int x1,y1,x2,y2;	
	find_letter(start, x1, y1);
	find_letter(end, x2, y2);

	return abs(x2-x1) + abs(y2-y1);
}

int main()
{
	// read a line
	string s;
	getline(cin, s);

	s = 'A' + s + '\n';

	int sum = 0;
	for(int i=0; i<(int)s.length()-1; i++){
		sum += count_steps(s[i], s[i+1]);	
	}
	cout << sum << endl;

	return 0;
}

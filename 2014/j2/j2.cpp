#include <iostream>
using namespace std;

int main()
{
	int V;
	string s;
	cin >> V;
	cin >> s;

	int A = 0;
	int B = 0;
	for(char c : s){
		if(c == 'A'){
			A++;
		}else{
			B++;
		}
	}

	if(A>B){
		cout << "A";
	}else if(A<B){
		cout << "B";
	}else{
		cout << "Tie";
	}

	cout << "\n";

	return 0;
}

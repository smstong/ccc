#include <iostream>
using namespace std;

int main()
{
	int M[2][2] = {
		{1, 2},
		{3, 4},
	};

	string actions;
	cin >> actions;

	for(unsigned int i=0; i<actions.length(); i++){
		if(actions[i] == 'V'){
			for(int r=0; r<2; r++){
				int t = M[r][0];
				M[r][0] = M[r][1];
				M[r][1] = t;
			}
		}else{
			for(int c=0; c<2; c++){
				int t = M[0][c];
				M[0][c] = M[1][c];
				M[1][c] = t;
			}

		}
	}
	for(int r=0; r<2; r++){
		cout << M[r][0] << " " << M[r][1] << "\n";
	}
	return 0;
}

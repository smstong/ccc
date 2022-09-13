#include <iostream>
using namespace std;

int main()
{
	int a[4][4];

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin >> a[i][j];
		}
	}

	int sum = 0;
	for(int i=0; i<4; i++){
		sum += a[i][0];
	}

	for(int i=0; i<4; i++){
		int s = 0;
		for(int j=0; j<4; j++){
			s += a[i][j];
		}
		if( s != sum ){
			cout << "not magic\n";
			return 0;
		}
	}

	for(int j=0; j<4; j++){
		int s = 0;
		for(int i=0; i<4; i++){
			s += a[i][j];
		}
		if (s != sum){
			cout << "not magic\n";
			return 0;
		}
	}

	cout << "magic\n";
	return 0;
}

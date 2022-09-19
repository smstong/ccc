#include <iostream>
using namespace std;

int main()
{
	int D[4];
	for(int i=0; i<4; i++){
		cin >> D[i];
	}
	if(D[0] == D[1] &&
			D[0] == D[2] &&
			D[0] == D[3]){
		cout << "Fish At Constant Depth";
	}else if(D[0] > D[1] &&
			D[1] > D[2] &&
			D[2] > D[3]){
		cout << "Fish Diving";
	}else if(D[0] < D[1] &&
			D[1] < D[2] &&
			D[2] < D[3]){
		cout << "Fish Rising";
	}else{
		cout << "No Fish";
	}
	cout << "\n";
	return 0;
}

#include <iostream>
using namespace std;

int main(){
	int P,C;
	cin >> P >> C;

	int F = P*50 - C*10;
	if(P > C){
		F += 500;
	}

	cout << F << endl;
	return 0;
}

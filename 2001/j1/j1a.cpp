#include <iostream>
using namespace std;

int main(){
	int H;
	cout << "Enter H:\n";
	cin >> H;

	int n=1;
	int d = 2;
	while(true){
		if(n<0){
			break;
		}
		for(int i=0; i<n; i++) cout << "*";
		for(int i=0; i<2*H-2*n; i++) cout << " ";
		for(int i=0; i<n; i++) cout << "*";
		cout << endl;

		if(n+d>H){
			d = -d;
		}
		n += d;
	}
	return 0;
}

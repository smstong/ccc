#include <iostream>
using namespace std;

int main(){
	int t,s,h;
	cerr << "Enter tine length:\n";
	cin >> t;
	cerr << "Enter tine spacing:\n";
	cin >> s;
	cerr << "Enter handle length:\n";
	cin >> h;

	// tines
	for(int i=0; i<t; i++){
		cout << "*";
		for(int j=0; j<s; j++){
			cout << " ";
		}
		cout << "*";
		for(int j=0; j<s; j++){
			cout << " ";
		}
		cout << "*\n";
	}

	// line
	for(int i=0; i<(3+s*2); i++){
		cout << "*";
	}
	cout << "\n";

	// handle
	for(int i=0; i<h; i++){
		for(int j=0; j<(1+s); j++){
			cout << " ";
		}
		cout << "*\n";
	}
	return 0;
}

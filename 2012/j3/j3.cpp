#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			cout << "*";
		}
		for(int j=0; j<k; j++){
			cout << "x";
		}
		for(int j=0; j<k; j++){
			cout << "*";
		}
		cout << "\n";
	}
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			cout << " ";
		}
		for(int j=0; j<k; j++){
			cout << "x";
		}
		for(int j=0; j<k; j++){
			cout << "x";
		}
		cout << "\n";
	}
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			cout << "*";
		}
		for(int j=0; j<k; j++){
			cout << " ";
		}
		for(int j=0; j<k; j++){
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}


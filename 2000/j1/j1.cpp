#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int dow;
	int days;
	cout << "Enter day:\n";
	cin >> dow;
	cout << "Enter the number of days in the month:\n";
	cin >> days;

	cout << "Sun Mon Tue Wed Thr Fri Sat\n";
	for(int i=0; i<dow-1; i++){
		cout <<"    ";
	}
	int dom = 1;
	for(int i=0; i<7-dow+1; i++){
		printf("%3d ", dom++);
	}	
	cout << endl;
	int left = days - (8-dow);
	for(int i=0; i<left; i++){
		printf("%3d ", dom++);
		if(i == left-1 || (i>0 && (i+1)%7==0)){
			cout << endl;
		}
	}
	return 0;
}

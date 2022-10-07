#include <iostream>
using namespace std;

int main()
{
	int a[13] = {9,7,8,0,9,2,1,4,1,8,0,0,0};
	cout << "Digit 11?";
	cin >> a[10];
	cout << endl;
	cout << "Digit 12?";
	cin >> a[11];
	cout << endl;
	cout << "Digit 13?";
	cin >> a[12];
	cout << endl;

	int sum = 0;
	int m = 1;
	for(int i=0; i<13; i++){
		if(i%2!=0){
			m = 3;
		}else{
			m = 1;
		}
		sum += a[i] * m;
	}
	cout << "The 1-3-sum is " << sum << endl;
	return 0;
}

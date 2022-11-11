#include <iostream>
using namespace std;

int main()
{
	int a[10] = {
		100,
		500,
		1000,
		5000,
		10000,
		25000,
		50000,
		100000,
		500000,
		1000000,
	};

	int sum = 0;
	for(int i=0; i<10; i++){
		sum += a[i];
	}

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int k;
		cin >> k; 
		sum -= a[k-1];
	}
	int offer;
	cin >> offer;

	int average = sum / (10-n);
	if(offer > average){
		cout << "deal" << endl;
	}else{
		cout << "no deal" << endl;
	}

	return 0;
}

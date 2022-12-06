#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int n;
	cin >> n;

	int max = 1;
	/*
	int i=1;
	while(true){
		if(i*i == n){
			max = i;
			break;
		}else if(i*i > n){
			max = i-1;
			break;
		}else{
			i++;
		}
	}
	*/
	max = (int)sqrt(n);
	cout << "The largest square has side length " << max << ".\n";
	return 0;
}

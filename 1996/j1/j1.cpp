#include <iostream>
using namespace std;

// input:
// - n > 1
// return: 
// - 0 for perfect
// - 1 for abundant
// - -1 for deficent
int dpa(int n){
	int sum = 0;
	for(int i=1; i<n; i++){
		if(n % i == 0){
			sum += i;
		}
	}
	if(sum == n){
		return 0;
	}else if(sum > n){
		return 1;
	}else{
		return -1;
	}
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int n;
		cin >> n;
		int r = dpa(n);
		if(r == 0){
			cout << n << " is a perfect number.\n";
		}else if(r > 0){
			cout << n << " is an abundant number.\n";
		}else{
			cout << n << " is a deficient number.\n";
		}
	}
	return 0;
}

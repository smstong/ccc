#include <iostream>

using namespace std;

// greatest common divisor
int gcd(int a, int b){
	int max = a>b ? a : b;
	int min = a>b ? b : a;
	int new_min = max % min;
	if(new_min == 0){
		return min;
	}
	return gcd(min, new_min);
}

int main(){
	int n,d;
	cout << "Numberator" << endl;
	cin >> n;
	cout << "Denomitor" << endl;
	cin >> d;
	cout << endl;

	int Q = n / d; // quotient
	int R = n % d; // remainder

	if(R != 0){
		int N = R;
		int D = d;
		int _g = gcd(N,D);

		N /= _g;
		D /= _g;

		cout << Q << " " << N << "/" << D;
	}else{
		cout << Q;
	}

	cout << endl;
	return 0;
}

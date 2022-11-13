#include <iostream>
using namespace std;

int main()
{
	int min, max;
	cin >> min >> max;

	int rsa = 0;
	for(int i=min; i<=max; i++){
		int divisors = 2;
		for(int d=2; d<=i/2; d++){
			if(i%d == 0){
				divisors++;
				if(divisors>4) break;
			}
		}
		if(divisors == 4){
			rsa++;
		}
	}

	cout << "The number of RSA numbers between " << min << " and " << max << " is " << rsa << "." << endl;
	return 0;
}

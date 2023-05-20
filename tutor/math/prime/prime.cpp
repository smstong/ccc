#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n==1){
	cout << "1 is neither a prime nor a composite number.\n";
	return 0;
    }
    int factorCount = 0;
    for(int i=1; i<=n; i++){
	if((n % i) == 0){
	    factorCount++;
	}
	if(factorCount > 2){
	    cout << n << " is a composite number.\n";
	    return 0;
	}
    }
    cout << n << " is a prime number.\n";
    return 0;
}


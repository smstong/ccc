/**************************************************************************
 * factorize a composite number as a product of PRIME numbers
 *
 * <Grade 6> chap 4, page 20
 *
 * (1) Write the composite number as the product of two factors.
 * (2) Continue to factorize each composite factor until all factors are
 *     prime numbers.
 * (3) Write the number as a product of prime factors.
 *
**************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n = f1 * f2
// return: 
//     - true for fuccess
//     - false if n is a prime
bool do_factorize(int n, int& f1, int& f2){
    for(int i=2; i<=n/2; i++){
	if(n % i == 0){
	    f1 = i;
	    f2 = n / i;
	    return true;
	}
    }
    return false;
}

vector<int> primeFactors;
void factorize(int n){
    int f1, f2;
    if (!do_factorize(n, f1, f2)){
	primeFactors.push_back(n);
    }else{
	factorize(f1);
	factorize(f2);
    }
}

int main(){
    int n;
    cin >> n;
    factorize(n);
    sort(primeFactors.begin(), primeFactors.end());
    for(int f : primeFactors){
	cout << f << ", ";
    }
    cout << endl;
    return 0;
}

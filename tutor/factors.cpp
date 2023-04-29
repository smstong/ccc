/**************************************************************************
 * <Canadian Curriculum Grade 6> Chapter 3, page 16.
 *
 * e.g. Find the factors of 12
 * 12 = 1 x 12
 *    = 2 x 6
 *    = 3 x 4
 *    = 4 x 3 <- Stop when you get a number you've already com across.
 *
 * The factors of 12 are 1,2,3,4,6, and 12.
 *
**************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(){
    int n;
    cin >> n;

    vi factors;

    for(int i=1;;i++){
	int r = n % i;
	if(factors.end() != find(factors.begin(), factors.end(), i)){
	    break;
	}
	if(r == 0){
	    factors.push_back(i);
	    factors.push_back(n / i);
	}
    }
    
    sort(factors.begin(), factors.end());

    for(auto f : factors){
	cout << f << ",";
    }
    cout << endl;

    return 0;
}

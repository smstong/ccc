#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

bool is_nasty(int n){
	vi sums;
	vi diffs;
	for(int i=1; i<=n/2; i++){
		if(n % i == 0){
			int f1 = i;
			int f2 = n / f1;
			int sum = f1 + f2;
			int diff = abs(f1 - f2);
			if(sums.end() != find(sums.begin(), sums.end(), diff) ||
			   diffs.end() != find(diffs.begin(), diffs.end(), sum)){
				return true;
			}
			sums.push_back(sum);
			diffs.push_back(diff);
		}
	}
	return false;
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int n;
		cin >> n;
		if(is_nasty(n)){
			cout << n << " is nasty\n";
		}else{
			cout << n << " is not nasty\n";
		}
	}
	return 0;
}

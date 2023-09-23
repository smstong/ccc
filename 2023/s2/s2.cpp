#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
	int N;
	vector<int> h;

	cin >> N;
	for(int i=0; i<N; i++){
		int hi;
		cin >> hi;
		h.push_back(hi);
	}

	int n;	// crop length
	for(n=1; n<=N; n++){
		// left is the start index
		int min = INT_MAX;
		int left, right;
		// min of crop with length of n
		for(left=0; (right=left+n-1) < N; left++){
			int sum = 0;
			for(int i=0; i<n/2; i++){
				sum += abs(h[left+i] - h[right-i]);
			}
			if(sum < min) {
				min = sum;
			}
		}
		cout << min << " ";
	}	
	return 0;
}

#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;

	int r=0;

	for(int k1=0;; k1++){
		int sum = k1*4;
		if(sum >= N){
			if(sum==N){
				r++;
			}
			break;
		}
		for(int k2=0;;k2++){
			int sum2 = sum + k2*5;
			if(sum2 >= N){
				if(sum2 == N){
					r++;
				}
				break;
			}
		}
	}
	cout << r << endl;
	return 0;
}

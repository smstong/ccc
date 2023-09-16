/*
 * An ajacent will remove the common side of both
 */
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> R1;
	vector<int> R2;
	int C;
	cin >> C;
	for(int i=0; i<C; i++){
		int n;
		cin >> n;
		R1.push_back(n);
	}
	for(int i=0; i<C; i++){
		int n;
		cin >> n;
		R2.push_back(n);
	}

	int sum = 0;
	for(int i=0; i<C; i++){
		if(R1[i] == 1){
			sum += 3;
		}
	}
	for(int i=0; i<C; i++){
		if(R2[i] == 1){
			sum += 3;
		}
	}

	// First Row
	for(int i=0; i<C; i++){
		if(R1[i] == 1){
			// if has a right ajacent black
			if(i+1<C && R1[i+1] == 1){
				sum -= 2;
			}
			// if has a down ajacent black
			if(i%2==0 && R2[i]==1){
				sum -= 2;
			}
		}
	}
	// Second Row
	for(int i=0; i<C; i++){
		if(R2[i] == 1){
			// if has a right ajacent black
			if(i+1<C && R2[i+1] == 1){
				sum -= 2;
			}
		}
	}

	cout << sum << endl;
}

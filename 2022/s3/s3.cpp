#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_k(vector<int>& piece, int k){
	int n=(int)piece.size();
	int count = 0;
	for(int start=0; start<n; start++){
		for(int end=start; end<n; end++){
			vector<int> sample;
			bool isGood = true;
			for(int i=start; i<=end; i++){
				if(sample.end() != find(sample.begin(), sample.end(), piece[i])){ // bad sample
					isGood = false;
					break;
				}
				sample.push_back(piece[i]);
			}
			if(isGood){
				count ++;
			}
			if(count > k) {
				return false;
			}
		}
	}
	return count == k;
}

// update index array for next
// return false if no more
bool next_permutation(vector<int>& I, int M){
	static auto cur = I.size()-1;

	// find the index to increase
	while(I[cur] == M){
		if(cur==0){
			return false;
		}
		cur--;
	}
	I[cur]++;

	// all index after this reset to 0
	for(auto i=I.size()-1; i!=cur; i--){
		I[i] = 0;
	}
	cur = I.size()-1;
	return true;
}

template<typename T>
void print_v(const vector<T>& v){
	for(auto e : v){
		cout << e << " ";
	}
	cout << endl;
}

int main(){
	int N,M,K;

	// generate piece
	//
	N = 3;
	M = 2;
	K = 5;
	cin >> N >> M >> K;

	vector<int> piece(N);
	vector<int> I(N);
	vector<int> C(M);

	for(int i=0; i<N; i++){
		I[i] = 0;
	}
	for(int i=0; i<M; i++){
		C[i] = i+1;
	}

	bool found=false;
	while(true){
		for(int i=0; i<N; i++){
			piece[i] = C[I[i]];
		}
		if(check_k(piece, K)){
			print_v(piece);
			found = true;
			break;
		}
		if(!next_permutation(I, M-1)){
			break;
		}
	}
	if(!found){
		cout << -1 << endl;	
	}
	return 0;
}

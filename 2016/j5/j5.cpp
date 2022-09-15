#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// P(n,k)
// return all possible sequences
vvi permute(const int n, int k)
{
	vvi M;
	if(k==1){
		for(int i=0; i<n; i++){
			vi row;
			row.push_back(i);
			M.push_back(row);
		}
		return M;
	}

	vvi _M = permute(n, k-1);
	for(int i=0; i<n; i++){
		for(int j=0; j<(int)_M.size(); j++){
			if(find(_M[j].begin(), _M[j].end(), i) != _M[j].end()) {
				continue;
			}
			vi row;
			row.push_back(i);
			for(auto e : _M[j]){
				row.push_back(e);
			}
			M.push_back(row);
		}
	}
	return M;
}

// P(a[n],n)
vvi P(int a[], int n)
{
	vvi M_;
	vvi M = permute(n,n);
	for(auto row : M){
		vi row_;
		for(auto e : row){
			row_.push_back(a[e]);
		}
		M_.push_back(row_);
	}

	return M_;
}

int min_speed(int a[], int b[], int n)
{
	auto M_a = P(a, n);
	auto M_b = P(b, n);

	int min = INT_MAX;
	for(auto r_a : M_a){
		for(auto r_b : M_b){
			int speed = 0;
			for(int i=0; i<n; i++){
				speed += (r_a[i] > r_b[i] ? r_a[i] : r_b[i]);
			}
			if(speed < min) {
				min = speed;
			}
		}
	}
	return min;
}
int max_speed(int a[], int b[], int n)
{
	auto M_a = P(a, n);
	auto M_b = P(b, n);

	int max = 0;
	for(auto r_a : M_a){
		for(auto r_b : M_b){
			int speed = 0;
			for(int i=0; i<n; i++){
				speed += (r_a[i] > r_b[i] ? r_a[i] : r_b[i]);
			}
			if(speed > max) {
				max = speed;
			}
		}
	}
	return max;
}

int main()
{
	int Q;
	cin >> Q;

	int N;
	cin >> N;

	vi a,b;
	for(int i=0; i<N; i++){
		int speed;
		cin >> speed;
		a.push_back(speed);
	}
	for(int i=0; i<N; i++){
		int speed;
		cin >> speed;
		b.push_back(speed);
	}

	if(Q==1){
		cout << min_speed(a.data(),b.data(),N);
	}else{
		cout << max_speed(a.data(),b.data(),N);
	}

	cout << "\n";

	return 0;

}


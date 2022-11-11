#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int motels[] = {
		0,
		990,
		1010,
		1970,
		2030,
		2940,
		3060,
		3930,
		4060,
		4970,
		5030,
		5990,
		6010,
		7000,
	};

	vector<int> M;
	for(auto e : motels){
		M.push_back(e);
	}

	int A,B,N;
	cin >> A >> B >> N;

	for(int i=0; i<N; i++){
		int m;
		cin >> m;
		M.push_back(m);
	}

	sort(M.begin(), M.end());



	return 0;
}

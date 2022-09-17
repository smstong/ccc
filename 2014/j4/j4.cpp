#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
	int K;
	int m;

	cin >> K;

	vi list;
	for(int i=0; i<K; i++){
		list.push_back(i+1);
	}

	cin >> m;
	vi R;
	for(int i=0; i<m; i++){
		int r;
		cin >> r;
		R.push_back(r);
	}


	vi old = list;
	vi left;
	for(auto r : R){
		left.clear();
		for(size_t i=0; i<old.size(); i++){
			if((i+1) % r != 0){
				left.push_back(old[i]);	
			}
		}
		old = left;
	}

	for(int i : left){
		cout << i << "\n";
	}

	return 0;
}

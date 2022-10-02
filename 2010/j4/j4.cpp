#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int min_cycle(const vi& v);
int main()
{
	int n;
	while(true){
		cin >> n;
		if(n <= 0){
			return 0;
		}
		vi _v(n);
		for(int i=0; i<n; i++){
			cin >> _v[i];
		}

		// edge condition
		if(n == 1){
			cout << 0 << "\n";
			continue;
		}

		vi v(n-1);
		for(int i=1; i<(int)_v.size(); i++){
			v[i-1] = _v[i] - _v[i-1];
		}

		int min = min_cycle(v);
		cout << min << "\n";
	}
}

int min_cycle(const vi& v)
{
	int min = 1;
	while(true){
		// set cycle
		vi cycle(min);
		for(int i=0; i<min; i++){
			cycle[i] = v[i];
		}

		// verify cycle
		bool ok = true;
		for(int i=0; i<(int)v.size(); i++){
			int j = i % min;
			if(v[i] != cycle[j]){
				ok = false;
				break;
			}
		}
		if(ok){
			break;
		}
		min++;
	}


	return min;
}

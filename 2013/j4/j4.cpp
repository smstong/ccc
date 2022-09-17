#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main()
{
	int T;
	int C;
	cin >> T;
	cin >> C;

	vi tasks;
	for(int i=0; i<C; i++){
		int t;
		cin >> t;
		tasks.push_back(t);
	}

	sort(tasks.begin(), tasks.end());
	int sum = 0;
	int done = 0;
	for(int t : tasks){
		sum += t;
		if(sum <= T){
			done ++;	
		}else{
			break;
		}
	}

	cout << done << "\n";

	return 0;
}

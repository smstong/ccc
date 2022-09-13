#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s.length();
	int max = 1;
	for(int i=0; i<n; i++){
		for(int j=1; j<=n-i; j++){
			string sub = s.substr(i, j);
			string sub_r = sub;
			reverse(sub_r.begin(), sub_r.end());

			if(sub == sub_r){
				max = j>max ? j : max;
			}
		}
	}

	cout << max << "\n";

	return 0;
}

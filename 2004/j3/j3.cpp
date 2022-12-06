#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	int n,m;
	cin >> n >> m;

	vector<string> ajectives;
	vector<string> nouns;

	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		ajectives.push_back(s);
	}
	for(int i=0; i<m; i++){
		string s;
		cin >> s;
		nouns.push_back(s);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << ajectives[i] << " as " << nouns[j] << endl;
		}
	}
	return 0;
}

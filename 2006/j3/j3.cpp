#include <iostream>
using namespace std;

bool sameKey(char c1, char c2){
	static string keys[] = {
		"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
	};
	
	for(string key : keys){
		if(key.find(c1) != string::npos && key.find(c2) != string::npos){
			return true;
		}
	}
	return false;
}

int getV(char c){
	int v[] = {
		1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,
	};
	return v[c-'a'];
}

int main(){
	string s;
	while(true){
		cin >> s;
		if(s == "halt"){
			break;
		}
		int sum = 0;
		for(int i=0; i<(int)s.length(); i++){
			sum += getV(s[i]);
			if(i == (int)s.length() - 1){
				break;
			}
			if(sameKey(s[i], s[i+1])){
				sum += 2;
			}
		}

		cout << sum << endl;
	}

	return 0;
}

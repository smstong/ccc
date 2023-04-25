#include <iostream>
using namespace std;

bool is_number(char c){
	return c >= '0' && c <= '9';
}

int main(){
	string s;
	cin >> s;
	for(size_t i=0; i<s.length(); i++){
		if(s[i] == '+'){
			cout << " tighten ";
		}else if(s[i] == '-'){
			cout << " loosen ";
		}else{
			cout << s[i];
		}
		if(i<(s.length()-1) && is_number(s[i]) && !is_number(s[i+1])){
			cout << endl;
		}
	}
	cout << endl;

	return 0;
}



#include <iostream>
using namespace std;

// substraction
void sub(string& s, char digit){
	int borrow = 0;
	int n = s.length();
	for(int i=n-1; i>=0; i--){
		int d_i = s[i]-'0';

		int d = 0;
		if(i == n-1){
			d = digit-'0';
		}

		int d_r = d_i - borrow - d;
		if(d_r < 0){
			d_r += 10;
			borrow = 1;
		}else{
			borrow = 0;
		}
		s[i] = d_r + '0';
		if(borrow == 0){
			break;
		}
	}
	if(s[0] == '0'){
		s = s.substr(1);
	}
}

void div11(string s) {
	string old = s;
	cout << s << endl;
	int len = s.length();
	while(len > 2){
		char digit = s[len-1];
		s = s.substr(0, len-1);
		sub(s, digit);
		cout << s << endl;
		len = s.length();
	}
	if(s.length() == 2 && s[0] == s[1]){
		cout << "The number " << old << " is divisible by 11.\n";
	}else{
		cout << "The number " << old << " is not divisible by 11.\n";
	}

}
int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		string s;
		cin >> s;
		div11(s);
		cout << endl;
	}
	return 0;
}

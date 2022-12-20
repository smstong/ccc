#include <iostream>
using namespace std;

// return the string representation of an int
string int_to_string(int n){
	string s = "";
	while(n>0){
		int rem = n % 10;
		char c = rem + 0x30;
		s = c + s;
		n = n / 10;
	}
	return s;
}

// return the int value of a string representation
int string_to_int(string s){
	int n = 0;
	for(int i=0, len=s.length(); i<len; i++){
		int w=1;
		for(int j=i; j<len-1; j++){
			w *= 10;
		}
		n += (s[i]-0x30) * w;
	}
	return n;
}

int main(){
	int n = 123456;
	cout << int_to_string(n)<<endl;

	cout << string_to_int("2345") << endl;
	return 0;
}


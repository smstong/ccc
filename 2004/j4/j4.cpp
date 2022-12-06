#include <iostream>
#include <string>
using namespace std;

char shift(char c, int offset){
	offset %= 26;
	char out = c + offset;
	if(out > 'Z'){
		out = out - 'Z' - 1 + 'A';
	}
	return out;
}

int main(void){

	string key;
	string in;
	getline(cin, key);
	getline(cin, in);

	string in2;
	for(char c : in){
		if(c <= 'Z' && c >= 'A'){
			in2.push_back(c);
		}
	}

	int k=0;
	string out;

	for(char c : in2){
		k = k % key.length();
		int offset = key[k] - 'A';
		out.push_back(shift(c, offset));
		k++;
	}

	cout << out << endl;

	return 0;
}

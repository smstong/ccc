#include <iostream>
using namespace std;

char unshift(char c, int n)
{
	char next = c - n;
	if(next < 'A'){
		next = 'Z'  - ('A' - next - 1);
	}
	return next;
}

int main()
{
	int K;
	string s;
	cin >> K;
	cin >> s;

	for(int i=0; i<(int)s.length(); i++){
		char c = unshift(s[i], 3*(i+1) + K);
		cout << c;
	}
	cout << "\n";
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for(char c : s){
		if( c != 'I' && c != 'O' && c!='S' && c!='H' && c!='Z' && c!='X' && c!= 'N'){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

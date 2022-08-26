#include <iostream>
using namespace std;

int main()
{
	string T, S;
	cin >> T;
	cin >> S;

	int where = -1;
	for(int i=0; i<(int)S.length(); i++){
		string shift = S.substr(i) + S.substr(0,i);
		if((where = T.find(shift)) >= 0){
			break;
		}
	}
	if(where >= 0){
		cout << "yes";
	}else{
		cout << "no";
	}
	cout << "\n";

	return 0;
}

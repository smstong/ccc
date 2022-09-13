#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for(int i=0; i<6; i++){
		char c;
		cin >> c;
		if(c == 'W') sum ++;
	}

	if(sum > 4){
		cout << "1";
	}else if(sum > 2){
		cout << "2";
	}else if(sum > 0){
		cout << "3";
	}else{
		cout << "-1";
	}

	return 0;
}


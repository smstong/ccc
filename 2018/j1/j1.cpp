#include <iostream>
using namespace std;

int main()
{
	int c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;

	if((c1 == 8 || c1 == 9) && (c4 == 8 || c4 == 9) && (c2 == c3)){
		cout << "ignore";
	}else{
		cout << "answer";
	}
	cout << "\n";
	return 0;
}

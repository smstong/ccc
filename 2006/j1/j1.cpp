#include <iostream>
using namespace std;

int main()
{
	int a[4][4] = {
		{461, 431, 420, 0},
		{100, 57, 70, 0},
		{130, 160, 118, 0},
		{167, 266, 75, 0},
	};

	int sum = 0;
	for(int i=0; i<4; i++){
		int n;
		cin >> n;
		sum += a[i][n-1];
	}
	
	cout << "Your total calorie count is " << sum  << "." << endl;

	return 0;
}

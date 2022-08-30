#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x1, x2;
	int y1, y2;
	int steps;

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> steps;

	int d = abs(x1-x2) + abs(y1-y2);
	if (steps >= d && (steps-d)%2 == 0){
		cout << "Y";
	}else{
		cout << "N";
	}

	cout << "\n";

	return 0;
}

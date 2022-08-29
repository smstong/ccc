#include <iostream>
using namespace std;

int main()
{
	int a1, a2, a3;
	int b1, b2, b3;

	cin >> a3 >> a2 >> a1;
	cin >> b3 >> b2 >> b1;

	int sum_a = 3*a3 + 2*a2 + a1;
	int sum_b = 3*b3 + 2*b2 + b1;

	if(sum_a > sum_b){
		cout << "A";
	}else if(sum_a < sum_b) {
		cout << "B";
	}else{
		cout << "T";
	}
	cout << endl;

	return 0;
}

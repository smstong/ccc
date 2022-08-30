#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, k;
	cin >> N >> k;

	int sum = 0;
	for(int i=0; i<k+1; i++){
		sum += (int)(N * pow(10, i));
	}

	cout << sum;

	return 0;
}

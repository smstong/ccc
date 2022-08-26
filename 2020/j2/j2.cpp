#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, R, P;
	cin >> P;
	cin >> N;
	cin >> R;

	int sum = 0;
	int i = 0;

	while(true){
		sum +=  N*pow(R, i);
		if(sum > P){
			cout << i << "\n";
			break;
		}
		i++;
	}
	return 0;
}

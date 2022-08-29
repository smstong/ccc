#include <iostream>
using namespace std;

int main()
{
	int N;
	string L1, L2;
	cin >> N >> L1 >> L2;

	int sum = 0;
	for(int i=0; i<N; i++){
		if(L1[i] == 'C' && L2[i] == 'C'){
			sum ++;
		}
	}
	cout << sum << "\n";
	return 0;
}

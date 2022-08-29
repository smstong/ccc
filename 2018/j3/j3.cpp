#include <iostream>
using namespace std;
int main()
{
	int d[4];
	cin >> d[0];
	cin >> d[1];
	cin >> d[2];
	cin >> d[3];

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			int min = (i<j ? i : j);
			int max = (i>j ? i : j);
			int sum = 0;
			for(int n=min; n<max; n++) {
				sum += d[n];
			}
			cout << sum << " ";
		}
		cout << "\n";
	}
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int L;
	cin >> L;

	for(int i=0; i<L; i++){
		int N;
		char x;
		cin >> N >> x;
		for(int j=0; j<N; j++){
			cout << x;
		}
		cout << "\n";
	}
	return 0;
}

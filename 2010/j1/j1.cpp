#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int start;
	int end;

	if(n % 2 == 0){
		start = n/2;
	}else{
		start = n/2 + 1;
	}
	end = n > 5 ? 5 : n;

	cout << (end-start+1) << "\n";
}

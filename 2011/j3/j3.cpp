#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int t1, t2, t3;
	cin >> t1 >> t2;

	int n = 2;
	while(true){
		t3 = t1 - t2;
		n++;
		if(t2 < t3){
			break;
		}
		t1 = t2;
		t2 = t3;
	}

	cout << n << "\n";

	return 0;
}

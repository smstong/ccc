#include <iostream>
using namespace std;

int main()
{
	int S, M, L;
	cin >> S;
	cin >> M;
	cin >> L;

	int score = 1*S + 2*M + 3*L;
	if(score < 10){
		cout << "sad";
	}else{
		cout << "happy";
	}

	cout << "\n";

	return 0;
}

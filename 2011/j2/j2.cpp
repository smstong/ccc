#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int h, M;
	cin >> h >> M;

	int t;
	for(t=1; t<M; t++){
		int A = -6*t*t*t*t + h*t*t*t + 2*t*t + t;
		if(A <= 0){
			break;
		}
	}
	if (t < M){
		cout << "The balloon first touches ground at hour:\n" << t << "\n";
	}else{
		cout << "The balloon does not touch ground in the given time.\n";
	}
	return 0;
}

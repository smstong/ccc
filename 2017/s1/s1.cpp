#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N;

	int A[100000];
	int B[100000];

	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	for(int i=0; i<N; i++){
		cin >> B[i];
	}

	int sumA = 0;
	int sumB = 0;
	K = 0;
	for(int i=0; i<N; i++){
		sumA += A[i];
		sumB += B[i];
		if(sumA == sumB){
			K = i+1;
		}
	}

	cout << K << "\n";

	return 0;
}

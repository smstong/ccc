#include <iostream>
using namespace std;

int main()
{
	int A[][2] = {
		{12, 34},
		{1, 11},
		{1, 23},
		{1, 35},
		{1, 47},
		{1, 59},
		{2, 10},
		{2, 22},
		{2, 34},
		{2, 46},
		{2, 58},
		{3, 21},
		{3, 33},
		{3, 45},
		{3, 57},
		{4, 20},
		{4, 32},
		{4, 44},
		{4, 56},
		{5, 31},
		{5, 43},
		{5, 55},
		{6, 30},
		{6, 42},
		{6, 54},
		{7, 41},
		{7, 53},
		{8, 40},
		{8, 52},
		{9, 51},
		{11, 11},
	};
	int D;
	cin >> D;

	int L = sizeof(A)/sizeof(A[0]);

	int N = D / 720; // the whole circles
	int d = D % 720;

	int m = 0;
	for(int i=0; i<L; i++){
		int mins = (A[i][0]==12?0:A[i][0])*60 + A[i][1];
		if(mins <= d){
			m++;
		}else{
			break;
		}
	}

	int sum = N*L + m;
	cout << sum << "\n";

	return 0;
}

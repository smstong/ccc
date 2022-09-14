#include <iostream>
#include <vector>
using namespace std;

// permutation via recursion
void permute(int a[], int n, int k)
{
	if(k == 0){
		cout << "\n";
		return;
	}
	for(int i=0; i<n; i++){
		cout << a[i] << ",";
		permute(a, n, k-1);
	}
}

int main()
{
	int a[] = {1,2,3};
	int n = 3;
	int k = 2;
	permute(a, n, k);

	return 0;
}


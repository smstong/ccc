#include <iostream>
#include <algorithm>

using namespace std;

void sort(int a[3])
{
	int i=0;
	for(i=0; i<3; i++){
		int minIndex = i;
		int min = a[i];
		for(int j=i+1; j<3; j++){
			if(a[j] < min){
				min = a[j];
				minIndex = j;
			}
		}
		if(minIndex != i){
			int t = a[i];
			a[i] = a[minIndex];
			a[minIndex] = t;
		}
	}
}

int main()
{
	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	sort(a);
	cout << a[1] << endl;

	return 0;
}

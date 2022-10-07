#include <iostream>
using namespace std;

int main()
{
	int a,b,c,sum;
	cin >> a >> b >> c >> sum;
	int N = 0;
	
	for(int i=0;;i++){
		int s = i*a;
		if(s > sum){
			break;
		}
		for(int j=0;; j++){
			int s = i*a + j*b;
			if(s > sum){
				break;
			}
			for(int k=0;;k++){
				int s = i*a + j*b + k*c;
				if( s > sum){
					break;
				}
				if(i+j+k>0){
					N++;
					cout << i << " Brown Trout, ";
					cout << j << " Northern Pike, ";
					cout << k << " Yellow Pickerel\n";
				}
			}
		}
	}
	cout << "Number of ways to catch fish: " << N << endl;
	return 0;
}

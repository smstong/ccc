#include <iostream>
using namespace std;

int main(){
	int m,n;
	cin >> m >> n;

	int p = 0;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(i+j == 10){
				p++;
				break;
			}
		}
	}

	if(p==1){
		cout << "There is 1 way to form the sum 10." << endl;
	}else{
		cout << "There are " << p << " ways to form the sum 10." << endl;
	}
	return 0;
}

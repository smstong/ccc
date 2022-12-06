#include <iostream>
using namespace std;

int main(){
	int n,m,p;
	cin >> n >> m;

	if(n+m < 10){
		p = 0;
	}else{
		int min = (n < m ? n : m);
		int max = (n > m ? n : m);
		p = (min>9?9:min) - ((10-max)<1?1:(10-max)) + 1;	
	}

	if(p==1){
		cout << "There is 1 way to form the sum 10." << endl;
	}else{
		cout << "There are " << p << " ways to form the sum 10." << endl;
	}

	return 0;
}

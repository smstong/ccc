#include <iostream>
using namespace std;

int main(){
	int H;
	cin >> H;
	int midR = (H+1)/2;
	for(int i=1; i<=H; i++){
		int c1, c2, c3;
		if(i <= midR){
			c1 = i*2-1;
		}else{
			c1 = (H+1-i)*2-1;
		}
		c3 = c1;
		c2 = 2*H - 2*c1;

		for(int j=0; j<c1; j++){
			cout << "*";
		}
		for(int j=0; j<c2; j++){
			cout << " ";
		}
		for(int j=0; j<c3; j++){
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

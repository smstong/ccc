#include <iostream>
using namespace std;

int main(){
	int C;
	do{
		cerr << "Enter number of pcitures:" << endl;
		cin >> C;
		if(C==0){
			break;
		}
		int W=1, H=C;
		int p = 2*(W+C);
		for(int w=1; w<C/2; w++){
			int reminder = C % w;
			if(reminder != 0){
				continue;
			}
			int h = C/w;
			if( 2*(w+h) < p){
				p = 2*(w+h);
				W = w;
				H = h;
			}
		}
		cout << "Minimum perimeter is " << p << " with dimensions " << W << " x " << H << endl;
	}while(C!=0);

	return 0;
}

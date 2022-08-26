#include <iostream>
using namespace std;

int main()
{
	int N;
	int X, Y;
	int minX=0, minY=0, maxX=0, maxY=0;
	cin >> N;

	for(int i=0; i<N; i++){
		scanf("%d,%d", &X, &Y);

		if(i==0){
			minX = X;
			maxX = X;
			minY = Y;
			maxY = Y;
		}else{
			if(X < minX) minX = X;
			if(X > maxX) maxX = X;
			if(Y < minY) minY = Y;
			if(Y > maxY) maxY = Y;
		}
	}
	cout << (minX-1) << "," << (minY-1) << "\n";
	cout << (maxX+1) << "," << (maxY+1) << "\n";

	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	double daytime, evening, weekend;
	cin >> daytime >> evening >> weekend;

	double A = (daytime<=100 ? 0 : (daytime-100)*25) + 15 * evening + 20 * weekend;
	double B = (daytime<=250 ? 0 : (daytime-100)*45) + 35 * evening + 25 * weekend;

	A = A/100;
	B = B/100;
	
	printf("Plan A costs %.2f\n", A);
	printf("Plan B costs %.2f\n", B);

	if(A > B){
		cout << "Plan B is cheapest.\n";
	}else if(A<B){
		cout << "Plan A is cheapest.\n";
	}else{
		cout << "Plan A and B are the same price.\n";
	}

	return 0;
}

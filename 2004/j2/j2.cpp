#include <iostream>
using namespace std;

int main(void){
	int lcm = 4*3*5; // least common multiple of 2,3,4,5	
	int X,Y;
	cin >> X >> Y;

	for(int year=X; year<=Y; year+=lcm){
		cout << "All positions would change in year " << year << endl;
	}
}

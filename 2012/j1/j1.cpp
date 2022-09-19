#include <iostream>
using namespace std;

int main()
{
	int limit;
	int speed;

	cout << "Enter the speed limit: ";
	cin >> limit;
	cout << "Enter the recorded speed of the car: ";
	cin >> speed;

	int delta = speed - limit;

	if(delta >= 31){
		cout <<"You are speeding and your fine is $500." << endl;
	}else if(delta >= 21){
		cout <<"You are speeding and your fine is $270." << endl;
	}else if(delta >= 1){
		cout <<"You are speeding and your fine is $100." << endl;
	}else{
		cout << "Congratulations, you are within the speed limit!" << endl;
	}
	return 0;
}

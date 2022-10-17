#include <iostream>

using namespace std;

int main()
{
	double weight;
	double height;

	//cout << "Enter weight: ";
	cin >> weight;
	//cout << "Enter height: ";
	cin >> height;

	double bmi = weight / (height*height);
	if(bmi > 25){
		cout << "Overweight";
	}else if(bmi >= 18.5){
		cout << "Normal weight";
	}else{
		cout << "Underweight";
	}
	cout << "\n";
	return 0;
}

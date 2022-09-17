#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

bool distinct(int year)
{
	vi digits;
	while(year != 0){
		int digit = year % 10;
		for(int d : digits){
			if(d == digit){
				return false;
			}
		}
		digits.push_back(digit);
		year = year / 10;
	}
	return true;
}

int main()
{
	int Y;

	cin >> Y;
	int D = Y + 1;
	while(!distinct(D)){
		D++;
	}
	
	cout << D << "\n";
	return 0;
}

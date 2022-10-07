#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	cout << t << " in Ottawa.\n";
	cout << (t-300+2400)%2400 << " in Victoria.\n";
	cout << (t-200+2400)%2400 << " in Edmonton.\n";
	cout << (t-100+2400)%2400 << " in Winnipeg.\n";
	cout << t << " in Toronto.\n";
	cout << (t+100)%2400 << " in Halifax.\n";

	int t_s = (t+130);
	int hour = t_s / 100;
	int min = t_s % 100;
	if(min >= 60){
		hour += 1;
		min -= 60;
	}
	t_s = hour*100 + min;
	cout << t_s << " in St. John's.\n";
	return 0;
}

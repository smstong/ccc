#include <iostream>
#include <utility>

using namespace std;

int main()
{
	cout << sizeof(pair<int, int>) << endl;
	cout << sizeof(pair<double, int>) << endl;

	// intialization
	pair<int, int> point(10,20);

	// get memebers
	cout << point.first << endl;
	cout << point.second << endl;

	// comparison of pairs
	pair<int, int> point2(10,20);
	cout << (point == point2) << endl;

	return 0;
}

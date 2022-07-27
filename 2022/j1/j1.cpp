#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int R, S, cakes;
	cin	>> R;
	cin >> S;
	cakes = R*8 + S*3;
	cout << cakes-28 << endl;
}

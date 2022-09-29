#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int antennas, eyes;
	cout << "How many antennas?\n";
	cin >> antennas;
	cout << "How many eyes?\n";
	cin >> eyes;

	if(antennas >= 3 && eyes <= 4){
		cout << "TroyMartian\n";
	}
	if(antennas <= 6 && eyes >= 2){
		cout << "VladSaturnian\n";
	}
	if(antennas <= 2 && eyes <= 3){
		cout << "GraemeMercurian\n";
	}
	return 0;
}

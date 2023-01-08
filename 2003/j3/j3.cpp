#include <iostream>
using namespace std;

int curPos = 1;

void move(int steps){
	int nextPos = curPos + steps;
	// ladders
	if(nextPos == 9){
		nextPos = 34;
	}
	if(nextPos == 40){
		nextPos = 64;
	}
	if(nextPos == 67){
		nextPos = 86;
	}

	// snakes
	if(nextPos == 54){
		nextPos = 19;
	}
	if(nextPos == 90){
		nextPos = 48;
	}
	if(nextPos == 99){
		nextPos = 77;
	}
	
	// not enough squares left
	if(nextPos > 100){
		nextPos = curPos;
	}

	curPos = nextPos;
}
int main(){
	
	while(true){
		int steps;
		cerr << "Enter sum of dice:\n";
		cin >> steps;
		move(steps);
		cout << "You are now on square " << curPos << endl;
		if(curPos == 100){
			cout << "You Win!\n";
			break;
		}
	}
	return 0;
}

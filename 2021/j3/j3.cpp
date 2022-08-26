#include <bits/stdc++.h>
using namespace std;

int main()
{
	string line;
	string direction;
	int d1,d2,steps,sum;

	while(true){
		cin >> line;
		if(line == "99999"){
			break;
		}

		d1 = stoi(line.substr(0,1));
		d2 = stoi(line.substr(1,1));
		steps = stoi(line.substr(2,3));
		sum = d1 + d2;
		if(sum == 0){
			// don't change direction
		}else if(sum % 2 == 0){
			direction = "right";
		}else{
			direction = "left";
		}

		cout << direction << " " << steps << "\n";
	}
    return 0;
}

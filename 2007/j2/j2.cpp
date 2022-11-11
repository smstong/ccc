#include <iostream>
using namespace std;

int main()
{
	string map[][2] = {
		{ "CU", "see you" },
		{ ":-)", "I'm happy" },
		{ ":-(", "I'm unhappy" },
		{ ";-)", "wink" },
		{ ":-P", "stick out my tongue" },
		{ "(~.~)", "sleepy" },
		{ "TA", "totally awesome" },
		{ "CCC", "Canadian Computing Competition" },
		{ "CUZ", "because" },
		{ "TY", "thank-you" },
		{ "YW", "you're welcome" },
		{ "TTYL", "talk to you later" },
	};


	int rowCount = sizeof(map)/sizeof(map[0]);

	string inStr;
	string outStr;
	while(true){
		cerr << "Enter phrase> ";
		cin >> inStr;
		outStr = inStr;
		for(int i=0; i<rowCount; i++){
			if(inStr == map[i][0]){
				outStr = map[i][1];
				break;
			}
		}
		cout << outStr << endl;

		if(inStr == "TTYL"){
			break;
		}
	}
	return 0;
}

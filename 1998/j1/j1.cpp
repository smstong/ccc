#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(256, '\n');
    for(int i=0; i<n; i++){
	string line;
	getline(cin, line);
	line += ' ';
	int s=0, e=0;
	for(int j=0; j<line.size(); j++){
	    if(line[j] == ' '){
		e = j-1;
		int wordLen = (e-s+1);
		if(wordLen == 4) {
		    for(int m=s; m<=e; m++){
			line[m] = '*';
		    }
		}
		s = j+1;
	    }
	}
	line = line.substr(0,line.size()-1);
	cout << line << endl;
    }
    return 0;
}

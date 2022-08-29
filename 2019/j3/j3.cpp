#include <iostream>
using namespace std;

int main()
{
	int L;
	cin >> L;
	for(int i=0; i<L; i++){
		string line;
		cin >> line;
		int N = 1;
		for(int j=1; j<(int)line.length(); j++){
			if(line[j] == line[j-1]){
				N++;
			}else{
				cout << N << " " << line[j-1] << " "; // pre pattern
				N = 1;
			}
		}
		cout << N << " " << line[line.length()-1] << "\n";  // last pattern

	}
	return 0;
}

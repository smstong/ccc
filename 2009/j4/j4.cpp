#include <iostream>
using namespace std;

// return the number of words included in this line
int get_one_line(int line_width, string words[], int N, int start)
{
	int width = 0;
	int wordsInLine = 0; 
	int i=0;
	for(i=start; i<N; i++){
		width += words[i].length();	
		if(i>start){
			width += 1; // space between words
		}
		if(width > line_width) {
			break;
		}
		wordsInLine ++;
	}
	return wordsInLine;
}

int main()
{
	string words[] = {"WELCOME", "TO", "CCC",  "GOOD", "LUCK", "TODAY"};
	int w;
	//cout << "Enter w:";
	cin >> w;
	//cout << "\n";

	int start = 0;
	while(start < 6){
		int n = get_one_line(w, words, 6, start);
		int len = 0;
		for(int i=0; i<n; i++){
			len += words[i+start].length();
		}
		int spaces = w - len;
		int avgSpaces;
		int extraSpaces;
		if(n > 1){
			avgSpaces = spaces / (n-1);
			extraSpaces = spaces % (n-1);
		}else{
			avgSpaces = spaces;
			extraSpaces = 0;
		}

		for(int i=0; i<n; i++){
			cout << words[i+start];
			if(i<n-1 || n==1){
				for(int j=0; j<avgSpaces; j++){
					cout << ".";
				}
			}
			if(extraSpaces > 0){
				cout << ".";
				extraSpaces --;
			}
		}
		cout << endl;
		start += n;
	}
	return 0;
}

#include <iostream>
using namespace std;

// return last word
string LastWord(string line){
	int lastSpace = line.rfind(" ");
	if(lastSpace == string::npos){
		return line;
	}
	return line.substr(lastSpace+1);

}
// return last syllable
string LastSyllable(string line){
	string vowels = "aeiou";
	string word = LastWord(line);
	int i=0;
	for(i=word.length()-1; i>=0; i--){
		if(vowels.find(word[i]) != string::npos){
			break;
		}
	}
	string sylable = word.substr(i>0?i:0);
	return sylable;
}

// lower string
string Lower(string S){
	string s = "";
	for(char C : S){
		char c = C;
		if(c>='A' && c<='Z'){
			c += 'a' - 'A';
		}
		s += c;
	}
	return s;
}
int main(){
	int n;
	cin >> n;
	cin.ignore();
	for(int i=0; i<n; i++){
		string poem[4];
		for(int j=0; j<4; j++){
			string line;
			getline(cin, line);
			poem[j] = Lower(LastSyllable(line));
		}

		if(poem[0]==poem[1] && poem[0] == poem[2] && poem[0] == poem[3]){
			cout << "perfect" << endl;
		}else{
			if(poem[0]==poem[1] && poem[2] == poem[3]){
				cout << "even" << endl;
			}else if(poem[0]==poem[2] && poem[1]==poem[3]){
				cout << "cross" << endl;
			}else if(poem[0]==poem[3] && poem[1]==poem[2]){
				cout << "shell" << endl;
			}else{
				cout << "free\n";
			}
		}
	}
	return 0;
}

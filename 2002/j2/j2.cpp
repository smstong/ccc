#include <iostream>
using namespace std;

int main(){
	cout << "Enter words to be translated:\n";
	string word;
	while(true){
		cin >> word;
		if(word == "quit!"){
			break;
		}
		int n = word.length();
		if(n > 4 && word[n-1] == 'r' && word[n-2] == 'o'){
			string vowels = "aeiouy";
			if(string::npos == vowels.find(word[n-3])){
				word = word.substr(0,n-2) + "our";
			}
		}
		cout << word << endl;
	}
	
	return 0;
}

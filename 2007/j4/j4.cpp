#include <iostream>
using namespace std;

string sort(const string s)
{
	string s1 = s;
	for(int i=0; i<(int)s1.length(); i++){
		int minIndex = i;
		char min = s1[i];
		for(int j=i+1; j<(int)s1.length(); j++){
			if(s1[j] < min){
				minIndex = j;
				min = s1[j]; 
			}
		}
		if(minIndex != i){
			char t = s1[i];
			s1[i] = s1[minIndex];
			s1[minIndex] = t;
		}
	}
	return s1;
}

string trim(const string s)
{
	string s1;
	for(auto c : s){
		if(c!=' '){
			s1 += c;
		}
	}
	return s1;
}

int main(){
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	s1 = sort(trim(s1));
	s2 = sort(trim(s2));

	if(s1 == s2){
		cout << "Is an anagram." << endl;
	}else{
		cout << "Is not an anagram." << endl;
	}

	return 0;
}

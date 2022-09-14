#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	string smile = ":-)";
	string sad = ":-(";
	int nSmile = 0;
	int nSad = 0;

	size_t found = s.find(smile);
	while(found != string::npos){
		nSmile ++;
		found = s.find(smile, found+smile.length());	
	}

	found = s.find(sad);
	while(found != string::npos){
		nSad ++;
		found = s.find(sad, found+sad.length());	
	}

	if(nSad == 0 && nSmile == 0){
		cout << "none";
	}else if(nSad > nSmile){
		cout << "sad";
	}else if(nSad < nSmile){
		cout << "happy";
	}else {
		cout << "unsure";
	}

	cout << "\n";

	return 0;
}


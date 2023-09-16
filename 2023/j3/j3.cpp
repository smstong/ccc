#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[] = {0,0,0,0,0};
	for(int i=0; i<N; i++){
		string s;
		cin >> s;
		for(int j=0; j<5; j++){
			if(s[j] == 'Y'){
				A[j]++;
			}
		}
	}

	// find the max element
	int max = A[0];
	for(int i=0; i<5; i++){
		if(A[i]>max){
			max = A[i];
		}
	}

	// find all element(s) that equal to max
	string out;
	for(int i=0; i<5; i++){
		if(A[i]==max){
			out += to_string(i+1) + ",";
		}
	}
	out = out.substr(0,out.length()-1);
	cout << out << endl;

	return 0;
}

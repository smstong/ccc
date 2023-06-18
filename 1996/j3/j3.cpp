#include <iostream>
using namespace std;

void sub_one(string& s){
	int n = s.length();

	if(s[n-1] == '1'){
		s[n-1] = '0';
	}else{
		for(int i=n-1; i>=0; i--){
			if(s[i] == '0'){
				s[i] = '1';
			}else{
				s[i] = '0';
				break;
			}
		}
	}
}

int count_ones(string s){
	int n = s.length();
	int sum = 0;
	for(int i=0; i<n; i++){
		if(s[i] == '1'){
			sum ++;
		}
	}
	return sum;
}
void f(int n, int k){
	string max = "";
	for(int i=0; i<n; i++){
		if(i<k){
			max += "1";
		}else{
			max += "0";
		}
	}

	string min = "";
	for(int i=0; i<n; i++){
		if(n-i <= k){
			min += "1";
		}else{
			min += "0";
		}
	}

	cout << "The bit patterns are\n";
	string s = max;
	while(true){
		if(count_ones(s) == k){
			cout << s << endl;
		}
		if(s == min){
			break;
		}
		sub_one(s);
		if(s == min){
			cout << s << endl;
			break;
		}
	}
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int n,k;
		cin >> n >> k;
		f(n,k);
		cout << endl;
	}

	return 0;
}

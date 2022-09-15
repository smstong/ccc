#include <iostream>
using namespace std;

bool is_v(char c)
{
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
char closest_v(char c)
{
	char v1 = '\0';
	char v2 = '\0';
	for(char c1=c; c1>='a'; c1--){
		if(is_v(c1)){
			v1 = c1;
			break;
		}
	}
	for(char c2=c; c2<='z'; c2++){
		if(is_v(c2)){
			v2 = c2;
			break;
		}
	}

	if(v1 == '\0'){
		return v2;
	}
	if(v2 == '\0'){
		return v1;
	}

	int d1 = c - v1;
	int d2 = v2 - c;

	if(d1 > d2){
		return v2;
	}else{
		return v1;
	}
}

char next_c(char c)
{
	if(c == 'z'){
		return c;
	}
	while(true){
		c++;
		if(!is_v(c)){
			return c;
		}
	}
}

int main()
{
	string s;
	cin >> s;
	for(auto c : s){
		if(is_v(c)){
			cout << c;
		}else{
			cout << c << closest_v(c) << next_c(c);
		}
	}

	cout << "\n";

	return 0;
}

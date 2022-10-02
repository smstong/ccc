#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,s;
	cin >> a >> b >> c >> d >> s;

	int A = 0;
	int B = 0;

	for(int i=0; i<s; i++){
		int A_i = i % (a+b);
		int B_i = i % (c+d);
		if(A_i < a){
			A++;
		}else{
			A--;
		}
		if(B_i < c){
			B++;
		}else{
			B--;
		}
	}
	if(A>B){
		cout << "Nikky";
	}else if(A==B){
		cout << "Tied";
	}else{
		cout << "Byron";
	}
	cout << "\n";
	return 0;
}

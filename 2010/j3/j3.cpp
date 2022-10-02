#include <iostream>
using namespace std;

int main()
{
	int A,B;
	int id;
	char X,Y;
	int n;

	A = 0;
	B = 0;
	while(true){
		cin >> id;
		switch(id){
			case 1:
				cin >> X >> n;
				if(X == 'A'){
					A = n;
				}else{
					B = n;
				}
				break;
			case 2:
				cin >> X;
				if(X == 'A'){
					cout << A << "\n";
				}else{
					cout << B << "\n";
				}
				break;
			case 3:
				cin >> X >> Y;
				if(X=='A'){
					if(Y=='A'){
						A += A;
					}else{
						A += B;
					}
				}else{
					if(Y=='A'){
						B += A;
					}else{
						B += B;
					}
				}
				break;
			case 4:
				cin >> X >> Y;
				if(X=='A'){
					if(Y=='A'){
						A *= A;
					}else{
						A *= B;
					}
				}else{
					if(Y=='A'){
						B *= A;
					}else{
						B *= B;
					}
				}
				break;
			case 5:
				cin >> X >> Y;
				if(X=='A'){
					if(Y=='A'){
						A -= A;
					}else{
						A -= B;
					}
				}else{
					if(Y=='A'){
						B -= A;
					}else{
						B -= B;
					}
				}
				break;
			case 6:
				cin >> X >> Y;
				if(X=='A'){
					if(Y=='A'){
						A = 1;
					}else{
						A /= B;
					}
				}else{
					if(Y=='A'){
						B /= A;
					}else{
						B = 1;
					}
				}
				break;
			case 7:
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}

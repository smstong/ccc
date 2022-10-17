#include <iostream>
using namespace std;

char a[5] = {'A', 'B', 'C', 'D', 'E'};
void btn_1() 
{
	char t = a[0];
	a[0] = a[1];
	a[1] = a[2];
	a[2] = a[3];
	a[3] = a[4];
	a[4] = t;
}

void btn_2()
{
	char t = a[4];
	a[4] = a[3];
	a[3] = a[2];
	a[2] = a[1];
	a[1] = a[0];
	a[0] = t;
}

void btn_3()
{
	char t = a[0];
	a[0] = a[1];
	a[1] = t;
}
int main()
{
	int b,n;
	while(true){
		cin >> b >> n;
		if(b==4){
			for(int i=0; i<5; i++){
				cout << a[i];
				if(i<4){
					cout << " ";
				}
			}
			cout << "\n";
			break;
		}else if(b==3){
			for(int i=0; i<n; i++){
				btn_3();
			}
		}else if(b==2){
			for(int i=0; i<n; i++){
				btn_2();
			}
		}else if(b==1){
			for(int i=0; i<n; i++){
				btn_1();
			}
		}else{
			continue;
		}
	}

	return 0;
}

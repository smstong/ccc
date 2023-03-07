#include <iostream>
using namespace std;

char S[9][5];
void seg_clear(){
	for(int i=0; i<9; i++){
		for(int j=0; j<5; j++){
			S[i][j] = ' ';
		}
	}
}
void seg_1(){
	S[1][0] = '*';	
	S[2][0] = '*';	
	S[3][0] = '*';	
}
void seg_2(){
	S[0][1] = '*';	
	S[0][2] = '*';	
	S[0][3] = '*';	
}
void seg_3(){
	S[1][4] = '*';	
	S[2][4] = '*';	
	S[3][4] = '*';	
}
void seg_4(){
	S[5][4] = '*';	
	S[6][4] = '*';	
	S[7][4] = '*';	
}
void seg_5(){
	S[8][1] = '*';	
	S[8][2] = '*';	
	S[8][3] = '*';	
}
void seg_6(){
	S[5][0] = '*';	
	S[6][0] = '*';	
	S[7][0] = '*';	
}
void seg_7(){
	S[4][1] = '*';	
	S[4][2] = '*';	
	S[4][3] = '*';	
}
void led(int n){
	seg_clear();
	switch(n){
		case 0:
			seg_1();
			seg_2();
			seg_3();
			seg_4();
			seg_5();
			seg_6();
			break;
		case 1:
			seg_3();
			seg_4();
			break;
		case 2:
			seg_2();
			seg_3();
			seg_7();
			seg_6();
			seg_5();
			break;
		case 3:
			seg_2();
			seg_3();
			seg_7();
			seg_4();
			seg_5();
			break;
		case 4:
			seg_1();
			seg_7();
			seg_3();
			seg_4();
			break;
		case 5:
			seg_2();
			seg_1();
			seg_7();
			seg_4();
			seg_5();
			break;
		case 6:
			seg_2();
			seg_1();
			seg_7();
			seg_4();
			seg_5();
			seg_6();
			break;
		case 7:
			seg_2();
			seg_3();
			seg_4();
			break;
		case 8:
			seg_1();
			seg_2();
			seg_3();
			seg_4();
			seg_5();
			seg_6();
			seg_7();
			break;
		case 9:
			seg_1();
			seg_2();
			seg_3();
			seg_4();
			seg_5();
			seg_7();
			break;
		default:
			break;
	}
	for(int i=0; i<9; i++){
		for(int j=0; j<5; j++){
			cout << S[i][j];
		}
		cout << endl;
	}
}

int main(){
	int n;
	cout << "Enter a digit between 0 and 9:" << endl;
	cin >> n;

	led(n);
	return 0;
}

															 #include <iostream>
using namespace std;

//#define DEBUG 1
// black - 1, white - 2, empty - 0

int a[8][8]; 

void print(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void init(char mode){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			a[i][j] = 0;
		}
	}
	switch(mode){
		case 'a':
			a[3][3] = 2;
			a[3][4] = 1;
			a[4][3] = 1;
			a[4][4] = 2;
			break;
		case 'b':
			for(int i=0; i<8; i++){
				a[i][i] = 1;
			}
			for(int i=0; i<8; i++){
				a[i][7-i] = 2;
			}
			break;
		case 'c':
			for(int i=0; i<8; i++){
				a[i][2] = 1;
				a[i][3] = 1;
				a[i][4] = 2;
				a[i][5] = 2;
			}
			break;
		default:
			break;
	}
}

void move(int R, int C, int me){
	int r = R-1;
	int c = C-1;
	a[r][c] = me;
	int opponent = (me == 1 ? 2 : 1);

	//horizontal
	int i,j;
	// left side
	for(j=c-1; j>=0; j--){
		if(a[r][j] != opponent){
			break;
		}
	}
	if(j>=0 && a[r][j] == me){ // flip
		for(int f=j+1; f<c; f++){
			a[r][f] = me;
		}
	}
	// right side
	for(j=c+1; j<8; j++){
		if(a[r][j] != opponent){
			break;
		}
	}
	if(j<8 && a[r][j] == me){
		for(int f=c+1; f<j; f++){
			a[r][f] = me;
		}
	}

	//vertical
	// up side
	for(i=r-1; i>=0; i--){
		if(a[i][c] != opponent){
			break;
		}
	}
	if(i>=0 && a[i][c] == me){
		for(int f=i+1; f<r; f++){
			a[f][c] = me;
		}
	}
	// down side
	for(i=r+1; i<8; i++){
		if(a[i][c] != opponent){
			break;
		}
	}
	if(i<8 && a[i][c] == me){
		for(int f=r+1; f<i; f++){
			a[f][c] = me;
		}
	}
	
	//diagnal
	//left-top
	for(i=r-1,j=c-1; i>=0 && j>=0; i--,j--){
		if(a[i][j] != opponent){
			break;
		}
	}
	if(i>=0 && j>=0 && a[i][j] == me){
		for(int fi=i+1, fj=j+1; fi<r && fj<c; fi++, fj++){
			a[fi][fj] = me;
		}
	}
	//right-bottom
	for(i=r+1,j=c+1; i<8 && j<8; i++,j++){
		if(a[i][j] != opponent){
			break;
		}
	}
	if(i<8 && j<8 && a[i][j] == me){
		for(int fi=r+1, fj=c+1; fi<i && fj<j; fi++, fj++){
			a[fi][fj] = me;
		}
	}
	// right-up
	for(i=r-1,j=c+1; i>=0 && j<8; i--,j++){
		if(a[i][j] != opponent){
			break;
		}
	}
	if(i>=0 && j<8 && a[i][j] == me){
		for(int fi=r-1,fj=c+1; fi>i && fj<j; fi--, fj++){
			a[fi][fj] = me;
		}
	}
	// left-down
	for(i=r+1,j=c-1; i<8 && j>=0; i++,j--){
		if(a[i][j] != opponent){
			break;
		}
	}
	if(i<8 && j>=0 && a[i][j] == me){
		for(int fi=i-1,fj=j+1; fi>r && fj<c; fi--, fj++){
			a[fi][fj] = me;
		}
	}
}

int main(){

	char mode;
	int n;
	cin >> mode >> n;

	init(mode);

#ifdef DEBUG
	print();
#endif
	for(int i=0; i<n; i++){
		int R, C;
		cin >> R >> C;
		move(R, C, i%2==0?1:2);
#ifdef DEBUG
		print();
#endif
	}
	
	int black = 0;
	int white = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(a[i][j] == 1) black++;
			if(a[i][j] == 2) white++;
		}
	}

	cout << black << " " << white << endl;
	return 0;
}

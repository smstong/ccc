#include <iostream>
using namespace std;

string W;
int R, C, H;
char G[100][100];

void forward(int r, int c, int dir, int& r2, int& c2){
	switch(dir) {
		case 0:
			c++;
			break;
		case 1:
			r--;
			c++;
			break;
		case 2:
			r--;
			break;
		case 3:
			r--;
			c--;
			break;
		case 4:
			c--;
			break;
		case 5:
			r++;
			c--;
			break;
		case 6:
			r++;
			break;
		case 7:
			r++;
			c++;
			break;
	}
	r2 = r;
	c2 = c;
}
void turnLeftAndForward(int r, int c, int dir, int& r2, int& c2, int& dir2){
	dir2 = (dir+2)%8;
	forward(r, c, dir2, r2, c2);
}
void turnRightAndForward(int r, int c, int dir, int& r2, int& c2, int& dir2){
	dir2 = ((dir-2)+8)%8;
	forward(r, c, dir2, r2, c2);
}

// test if cell (r,c) meets,then go to the next cell
// the next cell can be at 3 possible pos
// - forward
// - perpendicular left
// - perpendicular right
void TestChar(int r, int c, int dir, int seg, int i){
	if(r<0 || r>=R || c<0 || c>=C) return;
	if(W[i] != G[r][c]) return;
	if(i==int(W.length()-1)) {
		H++;
		return;
	}
	int r2, c2;
	forward(r, c, dir, r2, c2);
	TestChar(r2, c2, dir, seg, i+1);

	// if seg < 2 and this is not the first letter
	if(seg == 1 && i != 0){
		int dir2;
		turnLeftAndForward(r, c, dir, r2, c2, dir2);
		TestChar(r2, c2, dir2, seg+1,i+1);

		turnRightAndForward(r, c, dir, r2, c2, dir2);
		TestChar(r2, c2, dir2, seg+1,i+1);
	}
}
int main(){
	cin >> W >> R >> C;
	H = 0;

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> G[i][j];
		}
	}

	for(int r=0; r<R; r++){
		for(int c=0; c<C; c++){
			for(int d=0; d<8; d++){
				TestChar(r, c, d, 1, 0);
			}
		}
	}
	cout << H << endl;

	return 0;
}

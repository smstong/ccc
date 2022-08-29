#include <iostream>
using namespace std;

int M[100][100];
int N;

void rotate_clockwise()
{
	int T[100][100];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			T[j][N-1-i] = M[i][j];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			M[i][j] = T[i][j];
		}
	}
}
void rotate_counter_clockwise()
{
	int T[100][100];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			T[N-1-j][i] = M[i][j];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			M[i][j] = T[i][j];
		}
	}

}

bool is_original(){
	for(int i=1; i<N; i++){
		for(int j=0; j<N; j++){
			if(j>0 && (M[i][j] < M[i][j-1])){
				return false;
			}
			if(M[i][j] < M[i-1][j]){
				return false;
			}
		}
	}
	return true;
}
void print_M()
{
	for(int i=0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout << M[i][j];
			if(j<N-1){
				cout << " ";
			}
		}
		cout << "\n";
	}
}
int main()
{
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> M[i][j];
		}
	}
	for(int i=0; i<4; i++){
		if(is_original()){
			print_M();
			return 0;
		}
		rotate_clockwise();
	}
	for(int i=0; i<4; i++){
		if(is_original()){
			print_M();
			return 0;
		}
		rotate_counter_clockwise();
	}

	return 0;
}


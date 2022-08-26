#include <iostream>
#include <cstdlib>
using namespace std;

#define NODEBUG

bool *pCanvas = NULL;
int M,N,K;

// get cell at (r,c), r=[0...M], c=[0...N]
#define P_CELL(r,c) (pCanvas + ((r)*N + (c)))

void show()
{
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cout << *P_CELL(i,j) << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin >> M;
	cin >> N;
	cin >> K;

	pCanvas = (bool*)malloc(M*N*sizeof(bool));
	if(pCanvas == NULL){
		cout << "memory low\n";
		return -1;
	}
	for(int i=0; i<M*N; i++){
		pCanvas[i] = false;
	}

	char c;
	int k;
	for(int i=0; i<K; i++){
		cin >> c >> k;
		k = k-1; // change to start index with 0
		if(c == 'R'){
			for(int i=0; i<N; i++){
				*P_CELL(k, i) = !(*P_CELL(k,i));
			}
		}else{
			for(int j=0; j<M; j++){
				*P_CELL(j, k) = !(*P_CELL(j, k));
			}
		}
#ifdef DEBUG
		show();
#endif
	}

	int sum = 0;
	for(int i=0; i<M*N; i++){
		if(*(pCanvas+i)) sum ++;
	}

	cout << sum << "\n";
	return 0;
}

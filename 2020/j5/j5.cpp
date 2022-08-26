#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int *pD = NULL;
int M, N;
#define C(r,c) (pD + (r)*N + (c))

typedef vector<pair<int,int>> vp;

void show()
{
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cout << *C(i,j) << " ";
		}
		cout << "\n";
	}
}

// x = a * b
vp jump_cells(int x)
{
	vp cells;
	for(int i=1; i<=M; i++){
		if(x % i == 0){
			cells.push_back(i, x/i);
		}
	}
	return cells;
}

int main()
{
	cin >> M;
	cin >> N;

	pD = (int*) malloc(M*N*sizeof(int));

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			int v;
			cin >> v;
			*C(i,j)	= v;
		}
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<M; j++){
			vp cells = jump_cells(*C(i,j));
			for(int i=0; i<cells.size(); i++){
				cout << cells[i].first;
			}
		}
	}

	//show();
	free(pD);
	pD = NULL;
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int *trees = NULL;
int N,T;
int i,j;

int getxy(int row, int col)
{
	for(i=0; i<2*T; i++){
		if(trees[2*i] == row && trees[2*i+1] == col){
			return 1;
		}
	}
	return 0;
}

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))


void print_yard()
{
	int r,c;
	for(r=0; r<N; r++){
		for(c=0; c<N; c++){
			printf("%2d", getxy(r,c));
		}
		printf("\n");
	}
}

/* max square for a point as Left Top */
int maxSquare(int row, int col)
{
	int size = 0;
	int r,c;

	if(getxy(row,col) == 1){
		return 0;
	}
	for(size=1; size<=min(N-row, N-col); size++){
		for(r=row; r<row+size; r++){
			for(c=col; c<col+size; c++){
				if(getxy(r,c)==1){
					return size-1;
				}
			}
		}
	}
	return min(N-row, N-col);
}

int M()
{
	int r,c;
	int max = 0;
	for(r=0; r<N; r++){
		for(c=0; c<N; c++){
			int myMax = maxSquare(r,c);
			if ( myMax > max){
				max = myMax;
			}
		}
	}
	return max;
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &T);

	trees = (int*)malloc(2*sizeof(int)*T);

	for(i=0; i<T; i++){
		int R, C;
		scanf("%d %d", &R, &C);
		R--;
		C--;
		trees[i*2] = R;
		trees[i*2+1] = C;
	}
	
	printf("%d", M());
	return 0;
}

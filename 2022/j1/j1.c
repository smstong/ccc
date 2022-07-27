#include <stdio.h>
int main(int argc, char** argv)
{
	int R = 0;
	int S = 0;
	int cakes = 0;
	scanf("%d", &R);
	scanf("%d", &S);
	
	cakes = R*8 + S*3;
	printf("%d\n", cakes - 28);
}

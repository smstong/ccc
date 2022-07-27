#include <stdio.h>
int main(int argc, char** argv)
{
	int N = 0;
	int starPlayers = 0;

	scanf("%d", &N);
	
	int i=0;
	for(i=0; i<N; i++){
		int points = 0;
		int fouls = 0;
		int stars = 0;

		scanf("%d", &points);
		scanf("%d", &fouls);

		stars += points*5;
		stars -= fouls*3;

		if(stars > 40){
			starPlayers ++;
		}
	}
	printf("%d", starPlayers);
	if(starPlayers == N ){
		printf("+");
	}
	printf("\n");

	return 0;
}

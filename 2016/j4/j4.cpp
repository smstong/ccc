#include <cstdio>
using namespace std;

int main()
{
	int hour;
	int min;
	scanf("%d:%d", &hour, &min);

	int start = hour*60 + min;

	int slow1[2] = { 7*60, 10*60};
	int slow2[2] = {15*60, 19*60};

	int D = 120*2;

	while(D>0){
		if((start >= slow1[0] && start < slow1[1]) || 
		   (start >= slow2[0] && start < slow2[1])
		  ){
			D -= 1;
		}else{
			D -= 2;
		}
		start ++;
		if(start >= 24*60){
			start -= 24*60;
		}
	}
	hour = start / 60 % 24;
	min = start % 60;

	printf("%02d:%02d\n", hour, min);

	return 0;
}


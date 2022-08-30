#include <stdio.h>
#include <string.h>

int is_number(char c)
{
	if( c>='0' && c<='9' ) {
		return 1;
	}
	return 0;
}

int main(int argc, char** argv)
{
	char line[1024];
	scanf("%s", line);
	int n = strlen(line);
	int i=0;
	for(i=0; i<n; i++){
		if(line[i] == '+'){
			printf(" tighten ");
		}else if(line[i] == '-'){
			printf(" loosen ");
		}else{
			printf("%c", line[i]);
		}
		if((is_number(line[i]) && !is_number(line[i+1]))){
			printf("\n");
		}
		
	}
}


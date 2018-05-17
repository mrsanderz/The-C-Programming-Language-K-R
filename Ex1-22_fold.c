#include <stdio.h>
#define MAX_COL 5

int main()
{
	int c, i,j;
	char line[MAX_COL+1];

	i = 0;
	while( (c = getchar()) != EOF )
	{
		line[i] = c;
		i++;
		if( i == MAX_COL ){
            line[i+1] = '\0';
			printf( "%s\n", line );
			i = 0;
		}
		if(line[i-1] == '\n'){
            for(j=i;j<=MAX_COL+1;j++)
                line[j] = '\0';
            printf( "%s\n", line );
            i = 0;
            for(j=0;j<=MAX_COL+1;j++)
                line[j] = '\0';
		}
	}

	return 0;
}

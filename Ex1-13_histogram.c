#include <stdio.h>
#define IN 1
#define OUT 0
#define LENGTH 10
int main()
{
    int c, i, j, nwhite, nother, flag, count;
    int ndigit[10];

    nwhite = nother = flag = count = 0;
    for(i=0;i<10;i++)
        ndigit[i]=0;
    i = 0;
    while((c = getchar())!= EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            flag = OUT;
        }
        else if(flag == OUT){
            flag = IN;
            i++;
        }
        if(c != ' ' && c != '\t' && c != '\n')
            ndigit[i]++;
    }
    for(j=0;j<LENGTH;j++){
        for(i=1;i<10;i++){
            //("word%d: %d",i , ndigit[i]);
            if(ndigit[i]-LENGTH+j >=0)
                printf("*");
            else
                printf(" ");
        }
    printf("\n");
    }
}

/*int main()
{
    int c, i, nwhite, nother, flag;
    int ndigit[10];

    nwhite = nother = 0;
    for(i=0;i<10;i++)
        ndigit[i]=0;
    while((c = getchar())!= EOF)
        if(c <='9'&& c>= '0')
            ndigit[c-'0']++;
        else if(c == ' '||c == '\t'||c == '\n')
            nwhite++;
        else
            nother++;
    printf("digit");
    for(i=0;i<10;i++)
        printf(" %d",ndigit[i]);
    printf(" white=%d other=%d", nwhite, nother);
}
*/

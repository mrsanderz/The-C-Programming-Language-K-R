#include <stdio.h>
/*include in getop(), therefore no calc.h */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void){
    return bufp>0 ? buf[--bufp] : getchar() ;
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("too long\n");
    else
        buf[bufp++] = c; /*operator stored*/
}

/* author: Tony Lai */
/* EXERCISE 3-3  */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 15


void expand(char s1[], char s2[]);

int main()
{
    int i = 0;
    int c = 0;
    char v1[MAXLINE], v2[MAXLINE];
    while((c=getchar()) != '\n'){
        v1[i++] = c;
    }
    v1[i] = '\n';
    i++;
    v1[i] = '\0';

    //printf("%s", v1);
    expand(v1,v2);
    printf("%s", v2);

	return 0;
}


void expand(char s1[], char s2[]){
    int i = 0, j = 0;
    char c;


    while((c=s1[i++]) != '\0'){
        if((s1[i]) == '-' && s1[i+1]>=c){
            i++;
            while(c < s1[i])
                s2[j++] = c++;
        }
        else
            s2[j++] = c;
    }
    s2[j] = '\0';
}



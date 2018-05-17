/* author: Tony Lai */
/* EXERCISE 3-5*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 20  /* A SMALL NUMBER FOR TESTING */


void reverse(char after[], char before[]);
void get(int v1[]);
void itob(int n, char s[], int b);

int main()
{
    char output[MAXLINE];
    int input = 200;
    int base = 16;
    itob(-100, output, 16);
    //printf("%s",output);
	return 0;
}


void reverse(char after[], char before[]){
    int i = 0, j = 0;
    char temp;

    for(i=0,j=strlen(before)-1 ; i<strlen(before) ; i++, j-- ){
        after[j] = before[i];
        //printf("%d %d",j ,i);
        //after[i] = before[j];
    }
    after[i]='\0';
    //strcpy(after, before);
}

void get(int v1[]){
    int i = 0;
    int c = 0;
    //int v1[MAXLINE];
    while((c=getchar()) != '\n'){
        v1[i++] = c;
    }
    v1[i] = '\n';
    i++;
    v1[i] = '\0';
}

void itob(int n, char s[], int b){
    int sign = n;
    int i = 0;
    char s2[]={'\0'};
    if(sign<0)
        n=-n;
    while(n != 0){
        s[i++] = (n%b)+'0';
        n = n/b;
    }
    if(sign<0)
        s[i++]='-';
    s[i] = '\0';
    //printf("%s\n",s);
    reverse(s2,s);
    printf("%s",s2);
}





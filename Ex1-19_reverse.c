#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXLINE 1000

int get(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char after[], char before[]);
int aaaaa = 0;

int main()
{
    int len;
    int max;
    char rlongest[MAXLINE];
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while((len = get(line, MAXLINE))>0){
        if(len>max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("max:%d \nlongest:%s", max, longest);
    reverse(rlongest,longest);
    printf("reverse:%s\n", rlongest);
    return 0;
}

int get(char s[], int lim){
    int c, i;

    for(i=0;i<lim-1 && (c=getchar())!=EOF&& c!='\n';++i){
        if(c==' ' || c=='\t')
            --i;
        else
            s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i])!='\0')
        i++;
}

void reverse(char after[], char before[]){
int i, j;
char temp;

i = j = 0;

while((before[i])!='\0')
        i++;
j = i-1-1;

    for(i=0;i<j;++i){
        temp = before[j];
        before[j] = before[i];
        before[i] = temp;
        --j;
    }

i = 0;
while((after[i] = before[i])!='\0')
        i++;

}




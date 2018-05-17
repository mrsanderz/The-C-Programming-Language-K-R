/* author: Tony Lai */
/* EXERCISE 2-6~8   */

#include <stdio.h>
#include <string.h>
#define MAXLINE 15  /* A SMALL NUMBER FOR TESTING */

int c, i, lim, stop, n;
enum boolean {NO, YES};
char s[] = "hellosdgngfrh";
char s1[] = "g";
char *test;
int o;


int atoi(char a[]);
unsigned setbits( unsigned x, int p, int n, unsigned y );
unsigned rightrot( unsigned x, int n );
unsigned bitcount( unsigned x);

int main(){
    for( int i=0 ; i!=81 ; printf("%d*%d=%2d %c", (i/9+1), (i%9+1), (i/9+1)*(i%9+1), (i%9+1)==9?'\n':'\t' ) , i++);
	return 0;
}
/* PRTLINE: PRINT OUT LAST ARRAY LINE, SKIP INPUT BEYOND MAXLINE  */
int atoi(char a[]){
    int i = 0;
    int dec = 0;
    int n = 0;
    while(i<2){
        if(a[i]<='9'&&a[i]>='0')
            n = a[i]-'0';
        else if(a[i]<='F'&&a[i]>='A')
            n = 10+ (a[i]-'A');
        else if(a[i]<='f'&&a[i]>='a')
            n = 10+ (a[i]-'a');
    dec = 16*dec + n;
    i++;
    }
return dec;
}

unsigned setbits( unsigned x, int p, int n, unsigned y ){
	return (x>>(p-n) & ~(~0<<n)) | (y & (~0<<n));
}

unsigned rightrot( unsigned x, int n ){
    unsigned test;
    int length = 0;
    int i = 0;
    test = x;
    test = test | ~0;
    while(test != 0){
        test = (test >> 1);
        length++;
    }
    while(i < n){
        x = (x>>1) | (x << (length-1)) ;
        i++;
    }
    return x;
}

unsigned bitcount( unsigned x){
    int b;
    for (b=0 ; x!=0 ; x &= (x-1)){
        b++;
    }
return b;
}

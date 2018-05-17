/* author: Tony Lai  */
/* remove comments from C sources */

#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXLINE 1000

int main()
{
    char input[MAXLINE],c;
    int i;
    int flag_comment1 = OUT;
    int flag_comment2 = OUT;
    int flag_slash = OUT;
    int flag_star = OUT;
    i = 0;
	while ((c = getchar()) != EOF){
	    input[i] = c;

        if(input[i] == '/' && flag_slash == OUT)
            flag_slash = IN;

        /* check type "/*" */
        else if(input[i] == '*' && flag_slash == IN && flag_comment2 == OUT && flag_comment1 == OUT){
            i--;    //back to the first character of "/*"
            input[i] = '\0';
            flag_comment1 = IN;   // type "/*"
        }
        else if(input[i] == '*' && flag_comment1 == IN){
            flag_star = IN;
        }
        else if(input[i] == '/' && flag_comment1 == IN && flag_star == IN ){
            input[i] = '\0';
            flag_comment1 = OUT;
            flag_slash = OUT;
            flag_star = OUT;
            i--;
        }
        else if(input[i] != '/' && input[i] != '*' && flag_star == IN){
            flag_star = OUT;  //not a end
        }


        /* check type "//" */
        else if(input[i] == '/' && flag_slash == IN && flag_comment1 == OUT && flag_comment2 == OUT){
            i--;
            input[i] = '\0';
            flag_comment2 = IN;   //type "//"
        }
        else if(input[i] == '\n' && flag_comment2 == IN){
            flag_comment2 = OUT;  //close type "//"
            flag_slash = OUT;
        }

        /* check if comment or not */
        else if(input[i] != '/' && input[i] != '*' && flag_slash == IN && flag_comment1 == OUT && flag_comment2 == OUT){
            flag_slash = OUT;  //not a comment
            putchar(input[i]);
        }


        if(flag_comment1 == IN){
            input[i] = '\0';
            i--;
        }
        else if(flag_comment2 == IN){
            input[i] = '\0';
            i--;
        }


        i++;
	}
	i++;
	input[i] = '\0';
    printf("%s",input);
	return 0;
}

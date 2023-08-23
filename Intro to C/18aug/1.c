#include<stdio.h>
int main(){
    char s[1000];
    char c;
    //fgets(s,1000,stdin);
    //fgets(s,1000,stdin);
    //printf("%s\n",s);
    c = fgetc(stdin);
    printf("%c\n",ungetc(c,stdin));




    return 0;  
}

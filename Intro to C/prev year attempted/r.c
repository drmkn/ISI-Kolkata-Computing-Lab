#include <stdio.h>
# include <stdlib.h>
int main(){
    char **pp,**qq;
    pp = (char **)malloc(2*sizeof(char *));
    pp = (char **)malloc(2*sizeof(char *));
    *pp = "abfbnjkbnbnjkfn";
    *qq = "abfbnjkbnbnjkfn";
    //printf("%c",*(*(pp+1)+14));
    printf("%p\n",&pp);
    printf("%p",&qq);  


    return 0;
}
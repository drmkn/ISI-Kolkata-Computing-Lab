#include<stdio.h>

int main(){
    //int (*X)[10];
    int *X[10];
    printf("%ld\n",sizeof(X+10000000000000000));
    return 0;


}

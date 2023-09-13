#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n,m =100;
    int i;
    char **lines;
    lines = (char**)malloc(n*sizeof(char*));
    for(i = 0;i<n;i++) lines[i] = (char*)malloc(m*sizeof(char));
    for(i = 0;i<n;i++){
       if(NULL == fgets(lines[i],m,stdin)) break;
}
    n = i;
    for(i = 0;i<n;i++) printf("%d %d %s", i+1, strlen(lines[i]),lines[i]);


    return 0;
}

#include<stdio.h>
int main(){
    int m;
    int n;
    int x;
    float s[1000000];
    int k;
    int count = 0;
    int i = 0;
    int j = 0;
    printf("Enter the value of m,n and decimal points:\n");
    scanf("%d %d %d", &m, &n, &x);
    getchar();
    while(k != '\n'){
         scanf("%f",&s[count]); 
         count++;
         k = getchar();
         
    }
    for(;i<m;i++){
       for(;j < (i+1)*n;j++){
        printf("%.*f   ",x,s[j]);}
       printf("\n");}




    return 0;
}

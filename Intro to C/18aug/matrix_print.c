#include<stdio.h>
int main(){
    int m;
    int n;
    int x;
    int s;
    float k;
    int count = 0;
    //int row_count = 0;
    printf("Enter the value of m,n and decimal points:\n");
    scanf("%d %d %d", &m, &n, &x);
    getchar();
    //row_count++;
    while(s != '\n' && count < m*n){
         scanf("%f",&k); 
         if(count == 0){
           printf("%.*f   ",x,k);}
         else if(count%n != 0){
            printf("%.*f   ",x,k);}
         else{printf("\n");
              printf("%.*f   ",x,k); }
              
              //row_count++;}
         count++;
         s = getchar();
        // printf("%d",s);
         
    }
    printf("\n");
    if(count != m*n){
      printf("The input does not have exactly %d values\n",m*n);
    }
    else{ 1 == 1;}
    printf("\n");

    return 0;
}

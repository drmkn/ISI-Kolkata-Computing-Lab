#include<stdio.h>
int main(){
    int A[5];
    int c;
    int n;
    int count = 0;
    int sum = 0;
    int temp_max;
    int max;
    while(EOF != (c = getchar())){
         if(count < 5){
         for(; count < 5; ++count){
            //scanf("%d", &n);
            sum = sum + (int)c;
            A[count] = sum;
            //max = sum;
            getchar();
            c = getchar();
         }
         max = sum;}
         
         //scanf("%d", &n);
         c = getchar();
         sum  = sum  + (int)c;
         temp_max = sum - A[count%5];
         if(max < temp_max){
             max = temp_max;
            }
         A[count%5] = sum;
         count += 1;
         //c = getchar();
         
         
         
         
    
    
    }
    
    printf("%d\n", max);
    return 0;
} 

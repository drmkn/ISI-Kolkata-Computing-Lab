#include<stdio.h>
// Assuming that the numbers in the input are separated by ',' , ' ' etc. and also assuming that the input terminates when '/n' is encountoured.
int main(){
    int A[5]; //array for storing the last 5 cumulative sums
    int c;   
    int n; // input number
    int count = 0;
    int sum = 0; // cumulative sum
    int temp_max;
    int max;
    while(c != '\n'){
         for(; count < 5; count++){ // stores the first five cumulative sums in the array
            scanf("%d", &n);
            sum = sum + n;
            A[count] = sum;
            c = getchar();
         }
         max = sum; // initially the max is set to be the sum of first five numbers (may vary on further input)
         while(c != '\n'){
              scanf("%d", &n);
              sum  = sum  + n;
              temp_max = sum - A[count%5]; //next sum of consecutive 5 terms(it maybe our new maximum)
              if(max < temp_max){ // comparison
                max = temp_max; // updating the new maximum
              }
              A[count%5] = sum; // storing the cumulative sum (may be of further use)
              count += 1;
              c = getchar();
         
         
         }
         
    
    
    }
    
    printf("%d\n", max);
    return 0;
} 

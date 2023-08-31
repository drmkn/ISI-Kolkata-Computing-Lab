/* CLAB / 2023 / LT1 */
#include<stdio.h>
//#include "common.h"

int main(int ac, char *av[])
{
    /* BEGIN REMOVE */
    int c;
    long long int array[1000];
    long long int digit_c[10];
    long long int sorted[1000];
    long long int min;
    long long int sum;
    int count = 0 ;
    int flag = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    
    /* END REMOVE */
   /* for(;k<1000;k++){
        array[k]=0;} */
    
    while ('\n' != (c = getchar())) {
          array[i] = c;
          count++;
          i++;
          if(c == '9') digit_c[9]++; 
          else if(c == '8') digit_c[8]++; 
          else if(c == '7') digit_c[7]++;   
          else if(c == '6') digit_c[6]++; 
          else if(c == '5') digit_c[5]++; 
          else if(c == '4') digit_c[4]++; 
          else if(c == '3') digit_c[3]++; 
          else if(c == '2') digit_c[2]++; 
          else if(c == '1') digit_c[1]++; 
          else{ digit_c[0]++; }
    }
    //printf("%d",digit_c[9]);
    for(;j<10;j++){
       sum = sum + digit_c[j]*j;}
    //printf("%d",count);
    if(sum%3 == 1){
       if(digit_c[1]>0) {digit_c[1]--;count--;}
       else if(digit_c[4]>0) {digit_c[4]--;count--;}
       else if(digit_c[7]>0) {digit_c[7]--;count--;}
       else{printf("Cannot reduce ");}}
    else if(sum%3 == 2){
       if(digit_c[2]>0) {digit_c[2]--;count--;}
       else if(digit_c[5]>0) {digit_c[5]--;count--;}
       else if(digit_c[8]>0) {digit_c[8]--;count--;}
       else{int y;
            for(;y<2;y++){
               if(digit_c[1]>0) {digit_c[1]--;count--;flag++;}
               else if(digit_c[4]>0) {digit_c[4]--;count--;flag++;}
               else if(digit_c[7]>0) {digit_c[7]--;count--;flag++;}
               
               }
             if(flag != 2) printf("Cannot reduce ");  
                
            }}
    else{1==1;}
    
    for(i=0;i<10;i++){
       for(j=0;j<digit_c[9-i];j++){
          printf("%d",9-i);}
       }

    printf("\n");  

 /*   int r,s =0;
    for(;r<count;r++){
         for(;s<digit_c[];)


printf("%c",sorted[r]);}*/
    
    
    return 0;


   // return 0;
   // return 0;
}

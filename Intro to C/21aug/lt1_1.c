#include<stdio.h>
int main(){
    int count = 0;
    int zero_count = 0;
    int s;
    int i = 0;
    while('\n' != (s = getchar())){
         if(s == '0'){
           printf("0");
           zero_count++;
           count++;}
         else if(s == '1'){
           count++;
         } else {printf("Error\n");
                 break;}  
           
    
    
    }
    for(;i<(count-zero_count);i++){
       printf("1");
    }
    printf("\n");
    

    return 0;
}

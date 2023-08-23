#include<stdio.h>
int main(){
    int s[80];
    int c;
    int count = 0;
    while('\n' != (c = getchar()) ){
         s[count] = c;
         count++;
         //c = getchar();}
         }
    while(count != 0){
         printf("%c",s[count-1]);
         count--;
    
    }     
    
    
    return 0;
}

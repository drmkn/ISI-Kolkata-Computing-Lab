#include<stdio.h>
int main(){
    char s;
    int count = 0;
    int words = 0;
    
    while(EOF!= (s=getchar())){
          if(s == 'a' || s == 'e' || s == 'i'|| s == 'o'|| s == 'u'|| s == 'A'|| s == 'E'|| s == 'I'|| s == 'O'|| s == 'U'){
             count++;
          }
          else if(s == ' ' || s == '\n'){
             words++;
           
          }
          else{
             continue;
          }
          s = getchar() ;     
          
    
    }
    
    printf("vowels - %d\n",count);
    printf("words - %d\n",words);






    return 0;
}

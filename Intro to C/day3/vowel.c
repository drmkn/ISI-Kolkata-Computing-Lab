#include<stdio.h>
int main(){
    int s;
    //int total_count = 0;
    int vowel_count = 0;
    int words = 0;
    int check;
    //check = isalpha(getchar())
    //int space_count = 0;
    
    while(EOF!= (s=getchar())){
          check = isalpha()
          if(s == 'a' || s == 'e' || s == 'i'|| s == 'o'|| s == 'u'|| s == 'A'|| s == 'E'|| s == 'I'|| s == 'O'|| s == 'U'){
             vowel_count++;
          }
          else if(s == ' ' || s == '\n'){
             words++;
             //space_count++;
             if(space_count > 1 ){
              // if (total_count == 0)
                   //getchar();
                   //space_count=0;}
               //else{
               //space_count=0;}
             } else{
                continue;
              }
           
          }
          else{
             continue;
          }
          s = getchar() ;     
          
    
    }
    
    printf("vowels - %d\n",vowel_count);
    printf("words - %d\n",words);






    return 0;
}

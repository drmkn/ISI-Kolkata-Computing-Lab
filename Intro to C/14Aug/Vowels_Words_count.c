#include<stdio.h>
#include<ctype.h>
int main(){ // here by allowed letter we mean the alphabets and the digits.
    int c;
    int vowels_count=0;
    int word_count=0;
    
    while(EOF != (c = getchar())){
         if(isalpha(c) || isdigit(c) ){ // checks the starting allowed letter for a contagious word 
            while((isalpha(c)) || (isdigit(c))){//scans the given contagious word untill any non allowed symbol is found
                if(c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'|| c == 'A'|| c =='E'|| c == 'I'|| c == 'O'|| c == 'U'){vowels_count++;c = getchar();} //takes care of vowel count
                else{ c = getchar(); //skips any non vowel allowed letter in the contagious word
                     continue;}
                         
            }
           ++word_count; 
         }  
         else{ continue;}
    }
    
    printf("Vowels count:%d\n",vowels_count);
    printf("Words count:%d\n",word_count);



    return 0;
}

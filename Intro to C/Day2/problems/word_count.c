#include<stdio.h>

int main(){
    int count = 0;
    char c = getchar();
    
    while(c != '\n'){
         c = getchar();
         while(c != ' '){
              c = getchar();
              if(c == '\n'){
                //count += 1;
                 break; 
                 } else{
                  continue;}
                 
                      
         }  
         count = count + 1;  
    
    
    }
    
    printf("%d\n",count);
    
    
    return 0;
}



/// Some corner cases remaining (special characters and problems with space)

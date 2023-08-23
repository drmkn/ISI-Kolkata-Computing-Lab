#include<stdio.h>

int main(){
    int count = 0;
    int i = 0;
    char c = getchar();
    
    while(c != '\n'){
        if(c =='a'){
            count += 1;
            
        }
        else if(c =='e'){
          count += 1;        
        }
        else if(c =='i'){
          count += 1;        
        }
        else if(c =='o'){
          count += 1;        
        }
        else if(c =='u'){
          count += 1;        
        }
        else if(c =='A'){
          count += 1;        
        }
        else if(c =='E'){
          count += 1;        
        }
        else if(c =='I'){
          count += 1;        
        }
        else if(c =='O'){
          count += 1;       
        }
        else if(c =='U'){
          count += 1;        
        } 
        //else {
        c = getchar();
                
                
        } 
              
    printf("%d\n",count);
    return 0;
}

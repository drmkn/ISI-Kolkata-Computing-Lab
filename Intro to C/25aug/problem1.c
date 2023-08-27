#include<stdio.h>
int main(){
    int c;
    int s;
    int count= 1;
    s = getchar();
    c = s;
    int max = 1;
    //int temp_max = 1;
    int h = c;
    printf("\n");
    while(1){
         while(c == (s = getchar()) && EOF != s){
            count++;}
            //temp_max++;}
         if(max < count){
              max = count;
              h = c;}
         else{1==1;}    
         if(s == EOF){
            if(count == 1){
              printf("%c",c);}
            else{printf("%c%d",c,count);
                 }  
            break;}
         else{1==1;}   
         if(count > 1){ 
            printf("%c%d",c,count);
            //count = 0;
         
         }
         else{printf("%c",c);}
         c = s; 
         count = 1;    
         }
    printf("\n%c\n",h);     
    
    
  
   



    return 0;

}

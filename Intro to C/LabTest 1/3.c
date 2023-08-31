/* CLAB / 2023 / LT1 */

#include "common.h"
#include <math.h>

/* BEGIN REMOVE */
static double entropy(int min, int max)
{
    
}
/* END REMOVE */

int main(int ac, char *av[])
{
    int c;
    int count =0;
    int zero_count = 0;
    int weird = 0;
    float result;
    float p0;
    float p1;
    int i=0;
    float min,max,temp;

    while ('\n' != (c = getchar())) {
          if(c == '0'){
            count++;
            zero_count++;
          }
          else if(c == '1'){
            count++;  
          }
          else{weird++;
               count++;}
    }
    
    if(weird != 0){
      for(i=0;i<weird+1;i++){
         int c0,c1,tc;
         
         c0 = zero_count;
         c1 = count - zero_count - weird;
         tc = count;
         c0 += weird - i;
         c1 += i;
         //tc += weird;
         p0 = (float)c0/tc;
         p1 = (c1)/(float)tc;
         if(i==0){
         if(p0 == 0.0){
              temp=min=0.0;}
         else{ //temp = temp*-1;
               temp=min=max = -1*(p0*(log(p0)/log(2)) + p1*(log(p1)/log(2)));
               }}
         else{if(p0 == 0.0){
              temp=min=0.0;}
              else{
              temp = p0*(log(p0)/log(2)) + p1*(log(p1)/log(2));
              temp = temp*-1;
              if(temp < min) min = temp;
              else{1==1;}
              if(temp > max) max = temp;
              else{1==1;}}
 
         }
        
 

      }
     printf("%.3f %.3f",min,max);
    }
    else{ p0 = (float)zero_count/count;
          p1 = (count-zero_count)/(float)count;
          if(p0 == 0.0){
              printf("%.3f %.3f",0.0,0.0);}
          else{result = p0*(log(p0)/log(2)) + p1*(log(p1)/log(2));
          printf("%.3f %.3f",-1*result,-1*result);}
         
}
    

    return 0;
}

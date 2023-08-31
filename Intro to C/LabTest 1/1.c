/* CLAB / 2023 / LT1 */
//#include<stdio.h>
#include "common.h"

#define BLUE 0
#define RED 1

int main(int ac, char *av[])
{
    char c;
    float r_x_min;
    float r_x_max;
    float r_y_min;
    float r_y_max;
    float b_x_min;
    float b_x_max;
    float b_y_min;
    float b_y_max;
    float flag_r = 0;
    float flag_b = 0;
    /* BEGIN REMOVE */
   
    /* END REMOVE */
    float x, y;
    int n,i;
    
    scanf("%d", &n);
    
    int temp;
    for (i = 0; i < n; i++) {
      scanf("%f %f %c", &x, &y, &c);
      if(c=='R'){
        if(flag_r == 0){
          flag_r++;
          r_x_min = r_x_max = x;
          r_y_min = r_y_max = y;
        }
        else{
             if(r_x_min > x ) r_x_min = x;
             if(r_x_max < x ) r_x_max = x; 
             if(r_y_min > y ) r_y_min = y;
             if(r_y_max < y ) r_y_max = y;
        }
      }
      else{ 
          if(flag_b == 0){
          flag_b++;
          b_x_min = b_x_max = x;
          b_y_min = b_y_max = y;
        }
        else{
             if(b_x_min > x ) b_x_min = x;
             if(b_x_max < x ) b_x_max = x; 
             if(b_y_min > y ) b_y_min = y;
             if(b_y_max < y ) b_y_max = y;
        }
      }
      
    }
    //printf("%f   %f \n", b_y_min,b_y_max);
    int indicate = 0;
    if(r_y_min > b_y_max) {printf("X");indicate++;}
    if(r_y_max < b_y_min) {printf("X");indicate++;}
    if(r_x_max < b_x_min) {printf("Y");indicate++;}
    if(r_x_min > b_x_max) {printf("Y");indicate++;}
    
    if(indicate == 0){printf("Not possible");}
    printf("\n");
    

  

    return 0;
}

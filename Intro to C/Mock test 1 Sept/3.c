#include<stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n],dis[n],result[n];
    int i,j = 0;
    int max;
    for(;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) scanf("%d",&b[i]);
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
          if(a[i] == b[j]){
            dis[i] = abs(i-j);
            if(i==0){max = dis[0];break;}
            if(max < dis[i]) max = dis[i];break;
          
          }
       
       }
    
    
    }
    //printf("%d\n",max);
    int min,loca,locb;
    int flag = 0;
    for(i=0;i<n;i++){
       if(dis[i] == max){
         if(flag==0){
           min = a[i];
           loca = i;
           flag++;
         }
         else{
             if(min > a[i]){ min = a[i]; loca = i;}
         }
       
       }
    
    }
    for(i=0;i<n;i++){
       if(b[i] == min){
         locb = i;
       } 
    
    }
    printf("%d %d %d\n",min,loca,locb);


    return 0;
}

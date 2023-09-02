#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int i,j,k;
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    printf("\n");
    
    for(i=1;i<n+1;i++){
       if(n%i == 0){
          j = n/i;
          for(k=1;k<n+1;k++){
             if(k-1==0){printf("%d  ",a[k-1]);continue;}
             if((k-1)%j != 0){
               printf("%d  ",a[k-1]);
             }
             else{printf("\n%d  ",a[k-1]); }
          }
          printf("\n");
          printf("\n");
       
       }
       else{continue;}
    
    
    
    }


    return 0;
}

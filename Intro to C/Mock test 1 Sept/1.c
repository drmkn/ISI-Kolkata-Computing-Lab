#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    int a[n][n];
    int i,j=0;
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           scanf("%d",&a[i][j]);  
       }}
    //printf("%d\n",a[1][1]);   
     //printf("%d\n",a[0][1]); 
    int sum,spaces,s;
    spaces = n-1;
    //sum = n
    for(sum=0;sum<n;sum++){
    for(s=0;s<spaces;s++) printf(" ");
    if(sum==0) {printf("%d\n",a[0][0]);spaces--;} 
    else{
    for(i=0;i<sum+1;i++){
       //printf("%d %d",sum-i,i);   
       printf("%d ",a[sum-i][i]);}
       
        
        
    
    printf("\n");spaces--;}
    }
    spaces = 1;
    for(sum=n;sum<2*n-1;sum++){
    for(s=0;s<spaces;s++) printf(" ");
    for(i=0;i<sum;i++){
        if((i<n) && (sum - i < n)){
          printf("%d ",a[sum-i][i]);
        }
        else{continue;}
    }
    printf("\n");spaces++;
    }
    


    return 0;
}

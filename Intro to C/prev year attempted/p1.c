#include <stdio.h>
int main(){
    int N,m;
    
    scanf("%d",&N);m = N;
    //printf("%d%d",m,N);
    int A[N];
    int i = 0;
    for(;i<N;i++){
       A[i] = i+1;}
    //printf("%d %d %d %d %d %d",A[0],A[1],A[2],A[3],A[4],A[5]);   
    for(i=0;i<N;i++){
       for(int j = 0;j<N;j++){
       if(A[j] == m){printf("#");A[j]--;}
       else{printf(" ");}}
       printf("\n");
       m--;
       
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(){
    int m,n;
    scanf("%d",&m);scanf("%d",&n);
    char A[m*n][15];
    int i,j;int c;
    for(i=0;i<m*n;i++){
        scanf("%s",A[i]);
        if((i>(m-1)*n)&&((c=getchar()) == '\n')){break;}
    }
    //printf("%s",A[i]);
    int max_array[n];int temp;int count =0;int flag =0;
    for(i=0;i<n;i++){
        for(j=i+n;j<m*n;j++){
            if(flag == 0){
               temp = strlen(A[i]);
                max_array[i] = temp;flag++; 
            }
            
            else{
                if(strlen(A[j]) > temp){
                    //printf("%s\n",A[j]);
                    max_array[i] = strlen(A[j]);
                    temp = strlen(A[j]);
                }
            }
        }
            
        flag = 0;
        temp = 0;count = 0;
    }
    //printf("%s\n",A[1]);
    //printf("%s\n",A[4]);
    //printf("%d",max_array[2]);
    int k = i;
    for(i=0;i<k;i++){
        if(i == 0){
            printf("%s",A[i]);
            for(j = 0;j<=max_array[i%n] - strlen(A[i]);j++){putchar(' ');}
        }
        else if(i%n != 0){
            printf("%s",A[i]);
            for(j = 0;j<=max_array[i%n] - strlen(A[i]);j++){putchar(' ');}
        }
        else{putchar('\n');
            printf("%s",A[i]);
            for(j = 0;j<=max_array[i%n] - strlen(A[i]);j++){putchar(' ');}}
    }


    return 0;
}
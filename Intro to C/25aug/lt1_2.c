#include<stdio.h>
int main(){
    int array[100];
    int status;
    int count = 0;
    int flag = 0;
    int i = 0;
    int j = 0;
    int k = 0; 
    int r = 0;
    int s = 0;
    int c;
    while(-1 != (status = scanf("%d",&array[count]))){
        // status = scanf("%d",&array[count]);
         count++;
    }
    //printf("%d",array[count-1]);
    while(1){
         if(s%2 == 0){
           for(i=0;i<count-j-1-k;i++){
              if(array[i+k] > array[i+1+k]){c = array[i+1+k];array[i+1+k] = array[i+k];array[i+k]=c;flag++;}
              else{1==1;}
              }
            j++;
           }
         else{
             for(i=0;i<count-j-1-k;i++){
               if(array[count-i-2-j] > array[count-i-1-j]){c = array[count-i-1-j];array[count-i-1-j]= array[count-i-2-j];array[count-i-2-j]=c;flag++;}
               else{1==1;}
               
              }
             
             k++;}
         if(flag == 0){
         break;}
         else{1==1;}
         s++;
         flag = 0;
}   printf("\n");
    for(;r<count;r++){printf("%d ",array[r]);}
    //printf("\n%d",array[count-1]);
    return 0;

    }


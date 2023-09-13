#include<stdio.h>
int read_integers(int *data){
    int i = 0;
    int c;
    //int count = 0;
    while(EOF != (scanf("%d",&data[i]))){
       //  count++;
         i++;
         //*(data + count) = c;
         }
    return i;     
}
void reverse(int *array,int length){
     int temp,i;

     for(i=0;i<length/2 ;i++){
        temp = *(array + i); 
        *(array + i) = *(array + length - i - 1);
        *(array + length - i -1) = temp;
     }
          
     
     }
void print(int *array, int length){
     int i = 0;
     for(;i<length;i++){
        printf("%d ",*(array+i));
     }

}

int main(){
    int count;
    int data[100];
    //int count;
    count = read_integers(data);
    reverse(data,count);
    printf("\n");
    print(data,count);
    return 0;


}

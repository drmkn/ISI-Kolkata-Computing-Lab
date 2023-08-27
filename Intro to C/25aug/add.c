#include<stdio.h>
int main(){
    int s1[100];
    int s2[100];
    int c1 = 0;
    int c2 = 0;
    int count;
    int flag;
    int r[101];
    int c;
    while('\n' != ((c=getchar()))){s1[c1]=c;c1++;}
    while('\n' != ((c=getchar()))){s2[c2]=c;c2++;}
    if(c1 > c2) {count = c1;flag = 1;}
    else{count = c1;} 
    while(1){
        if(flag==1){
           int i = 0;
           for(;i<c2;i++){
              s2[count-i-1] = s2[c2-1-i];
              }
           for(i=0;i<count-c2;i++) s2[i] = '0';
           break;   
        }
        else{break;}
    }
    int j = 0;
    for(;j<count;j++){
       printf("%c",s2[])}
    
          
    return 0;
}

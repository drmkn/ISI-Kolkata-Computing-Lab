#include<stdio.h>
#include<string.h>
int main(){
    //char str1[8] = {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'};
    int i;
    int j;
    //printf("%s\n", str1);
    //for(i=0; i<8; i++) printf("%c\n", str1[i]);
    //str1[0] ='a'; str1[1] ='b'; str1[2] ='c'; str1[3] ='\0';
    //strcpy(str1,"abc");
    //printf("%s\n", str1);
    for(j=0;j<15;j++){
          char str1[8] = {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'};
          strncpy(str1,"abcdefghijkl",j);
          for(i=0;i<15;i++){
             printf("%d %c %d\n",j, str1[i], str1[i]);
          
          }
       
       }
     

    return 0;
}

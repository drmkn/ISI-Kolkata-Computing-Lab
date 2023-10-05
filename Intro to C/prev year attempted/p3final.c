#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_compare(char *a,char *b){ //returns smaller string - 1 for first string,-1 for second string and 0 for equal string
     int l_a = strlen(a);int l_b = strlen(b);int result;int i;int flag=0;int min;int arg;
     if(l_a <= l_b){min = l_a;arg = 0;}
     else{min = l_b;arg = 1;}
     for(i = 0;i<min;i++){
          if(*(a+i) - '0' < *(b+i) - '0'){flag++;result = -1;break;}
          else if(*(a+i) - '0' > *(b+i) - '0'){flag++;result = 1;break;}
          else{continue;}
     }
     if(flag == 0){
          if(arg == 0){if(l_b == min){result = 0;}
                    else{result = -1;}}
          else{result = 1;}
     }
     return result;
}
int main(int ac, char **av){
    char **pp,*temp;
    int c,N,size;
    FILE *fp;
    int max = 2048;
    int i,j;
    char string[max];
    fp = fopen(av[1],"r");
    if(NULL == fp){
       printf("Could not open file %s\n",av[1]); 
    }
    N = 0;
    size = 1;
    pp = (char **)malloc((size)*sizeof(char*));
    while(NULL != fgets(string,max,fp)){
          if(string[strlen(string)-1] == '\n'){
          string[strlen(string)-1] = '\0';}
         N++;
         if(N < size/2 + 1){
           *(pp+N-1) = (char *)malloc((strlen(string)+1)*sizeof(char));
           strcpy(*(pp+N-1),string);
         }
         else{size = 2*size;
              pp = (char **)realloc(pp,size*sizeof(char *));
              *(pp+N-1) = (char *)malloc((strlen(string)+1)*sizeof(char));
              strcpy(*(pp+N-1),string);
         }   
    }
    for(i=0;i<N;i++){ //sorting the strings
     for(j=i;j<N;j++){
          if(string_compare(*(pp+i),*(pp+j)) == -1){continue;}
          else{temp = *(pp+i);
               *(pp+i) = *(pp+j);
               *(pp+j) = temp;}
     }
    }

     //for(int i=0;i<N;i++) printf("%s\n",*(pp+i));
    //printf("%d",string_compare("00","00"));
    int count = 0;
    i = 0;
    j = 0;
    //printf("%d",string_compare(*(pp+1),*(pp+2)));
    //printf("%d %d",strlen(*(pp+1)),strlen(*(pp+2)));
    while(j < N){
          while((j<N)&&(string_compare(*(pp+i),*(pp+j)) == 0)){
               j++;
          }
          count = j-i;
          //printf("%d %d\n",i,j);
          printf("%s %d\n",*(pp+i),count);
          i = j;
     }
    
    
        
    
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av){
    char **pp;
    int c,N,size;
    FILE *fp;
    int max = 2048;
    //char string[max];
    fp = fopen(av[1],"r");
    if(NULL == fp){
       printf("Could not open file %s\n",av[1]); 
    }
    N = 0;
    size = 1;
    pp = (char **)malloc((size)*sizeof(char*));
    while(NULL != fgets(char string[max],max,fp)){
         N++;
         if(N < size/2 + 1){
           *(pp+N-1) = string;
         }
         else{size = 2*size;
              pp = (char **)realloc(pp,size*sizeof(char *));
              *(pp+N-1) = string;
         }
         
    }
    for(int i=0;i<N;i++) printf("%s\n",*(pp+i));


    /*pp = (char **)malloc((4)*sizeof(char*));
    char a[max],a1[max];
    //char string[10];
    
    fgets(string,max,fp);
    *pp = string;
    printf("%s",*pp);
    fgets(string,max,fp);
    *(pp+1) = string;
    printf("%s",*(pp+1));*/	
    
    
        
    
    
    return 0;
}

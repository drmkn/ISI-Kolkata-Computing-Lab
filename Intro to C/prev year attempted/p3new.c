#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_compare(char *a,char *b){ //returns smaller string acc to lexicographical order
     int l_a = strlen(a);int l_b = strlen(b);int min;int result;int i;int flag=0;
     if(l_a <= l_b){min = l_a-1;}
     else{min = l_b-1;}
     for(i = 0;i<min;i++ ){
         if(*(a+i) - '0' <= *(b+i) - '0'){continue;}
         else{result = 1;flag++;break;}
     }
     if(flag == 0){
          if(l_a <= l_b){result = 0;}
          else{result = 1;}
     }
     //printf("%d\n",l_a);
     return result;
}
/*char *copy(char *a, char *b){
     char temp;
     temp = *a;
     *a = *b;
     *b = temp;
     return b;
}*/


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
         N++;
         if(N < size/2 + 1){//*pp = swap(*pp,*(pp+1));
           *(pp+N-1) = (char *)malloc((strlen(string))*sizeof(char));
           strcpy(*(pp+N-1),string);
         }
         else{size = 2*size;
              pp = (char **)realloc(pp,size*sizeof(char *));
              *(pp+N-1) = (char *)malloc((strlen(string))*sizeof(char));
              strcpy(*(pp+N-1),string);
         }
         
    }
    //printf("%d",string_compare("0000","1"));
    for(i=0;i<N;i++){
     for(j=i+1;j<N;j++){
          if(string_compare(*(pp+i),*(pp+j)) == 0){continue;}
          else{temp = *(pp+i);
               *(pp+i) = *(pp+j);
               *(pp+j) = temp;}


     }

    }


    //printf("%d",string_compare(*(pp),*(pp+1)));
    for(int i=0;i<N;i++) printf("%s\n",*(pp+i));
    //*pp = copy(*pp,*(pp+1));
    //*(pp+1) = copy(*pp,*(pp+1));
    //char *temp;
    //temp = *pp;
    //*pp = *(pp+1);
    //*(pp+1) = temp;
    //for(int i=0;i<N;i++) printf("%s\n",*(pp+i));
    //printf("%d %d",'1'-'0','0'-'0');


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

#include<stdio.h>
#include<stdlib.h>
int main(int ac, char **av){
    int n;
    FILE *fp;
    int c;
    int current_line = 1;
    if(ac != 3){
       printf("Usage:%s <line number> <filename>\n",av[0]);
       exit(1);
    }
    n = atoi(av[1]);
    if(n<=0){
      printf("Line number should be a positive integer");
    }
    fp = fopen(av[2],"r");
    if(NULL == fp){
       printf("Could not open file %s\n",av[2]); 
    }
    while(current_line < n){
         do{c = fgetc(fp);}
         while(c!=EOF && c!='\n');
         if(c==EOF){printf("Not enough lines \n");exit(1);}
         current_line++;


    }
    while(EOF != (c=fgetc(fp))){
         putchar(c);
         if(c=='\n') break;

    }



    return 0;
}
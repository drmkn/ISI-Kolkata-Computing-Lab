#include<stdio.h>
#include<stdlib.h>

int main(int ac, char **av){
    FILE *fp;int c;
    fp = fopen(av[1],"r");
    if(NULL == (fp = fopen(av[1],"r"))){
        fprintf(stderr,"Could not open file\n"); //fprintf just shows the rroe on terminal instead in the file
        //printf(stderr,"Could not open file\n"); printf shoes the error message in the output file and not on terminal
        exit(1);
    }
    while(EOF != (c=fgetc(fp))){
        printf("%c\n",c);
    }
    fclose(fp);

}

//define MAX_STRING_SIZE 256
//typedef char DATA[MAX_STRING_SIZE];
//typedef char *DATA;
//strdup(s); ccreate copy of string


//char inbuf[BUF_LEN];
//while(NULL != fgets(inbuf,BUF_LEN,fp)){
 //   push(&S,strdup(inbuf));
//}
#include<stdio.h>

int main(int ac, char **av){
    FILE *fp;int c;
    fp = fopen(av[1],"r");
    while(EOF != (c=fgetc(fp))){
        printf("%c\n",c);
    }
    fclose(fp);

}
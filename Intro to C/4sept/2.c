#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int ii,i,n,r,filesize;
int rows = 100,cols = 10000;
    char *temp;
    char **mat;
    if(NULL == (temp = (char*) malloc(rows*cols*sizeof(char))) ||NULL == (mat = (char**) malloc(rows *sizeof(char*))));/*ERR_MESG("Outofmemory");*/
    


    for(ii = 0; ii < rows; temp += cols, ii++)mat[ii] = temp;
    filesize = fread(temp,sizeof(char),1000000,stdin);
    n =filesize;
    r=0;
    mat[r] = temp;
    for(i=0;i<n;i++){
       if(temp[i] == '\n'){
           temp[i] = '\0';
           r++;mat[r] = temp+i+1;
    	}


   }
    for(i=0;i<r;i++) puts(mat[i]);
    

  
    
    



    return 0 ;
}

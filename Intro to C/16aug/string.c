#include<stdio.h>
#include<string.h>
int main(){
    char *s;
    char *t;
    char u[128] = "A very long string";      
    s = "Hello";
    //printf("%s\n",s);
    t = "Hi";
    //printf("%s\n",t);
    //printf("%d\n",strcmp(s,t));
    //t = "Example";
    //printf("%d\n",strcmp(s,t));
    //strcpy(u,t);
    //printf("%s\n",u);
    //strcpy(u,s);
    //printf("%s\n",u);
    //strcpy(s,t);
    //printf("%s",s);

    //strncpy(u,s,4);
    //printf("%s\n",u);

    strncpy(u,s,3);
    printf("%s\n",u);
    
    
    

   





   return 0;




}

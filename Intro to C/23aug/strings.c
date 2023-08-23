#include<stdio.h>
#include<string.h>
int main(){
    /*char *str1 = "Dhruv R";
    int i;
    for(i=0;i<10;i++){printf("%c %d\n",str1[0],str1[0]);
    str1++;}
    //printf("%c",str1[0]);*/
    
    char*str1 ="Style1";
    char str2a[] ="Style2A";
    char str2b[16] ="Style2B";
    /*printf("%p\n",str1);
    str1 = "Another string";
    printf("%p\n",str1);*/
    //str1 = str2a;
    //str1[4] = 'X';
    //printf("%p\n",str1);
    //printf("%s\n",++str1);
    //printf("%s\n",++str2a);
    char a[32] ="Introduction", b[32] ="Programming", *s, *t;
    s = a; t = b;
    while(*s++ = *t++){printf("%s\n",a);}
    printf("%s\n",a);
    //printf("%p\n",str2b);
    //strcat(str2a, str2b);
    //printf("%p\n",str2b);
    //printf("%s\n",str2a);
    
    
    
    
    return 0;
}

#include<stdio.h>
int main(){
   float f = 1.75;
   char c[] ="Abc";
   char s[10];
   char a = '^';
   //printf("%d\n",c);
   //printf("%c\n",c);
  // printf("%d\n",f); //gives warning but outputs unexpected number changing every time
   //printf("%d\n",(int)f);
   //putchar('s'); // no new line
   //puts(c); // does new line
   //printf("Abc"); // no new line
  // printf("mtc23%02d:\n",6); //outputs mtc2306
   //printf("mtc23%2d:\n",6); //outputs mtc23 6
   //printf("mtc23%10d:\n",6); //outputs mtc23         6 (9 gaps)
   //printf("%.2f\n",1.345);
   //printf("%.8d:\n",77);
   //printf("%ld\n",37092870980);
   //printf("%d\n",sizeof(int));
   //printf("%zd\n",sizeof(int)); 
   //printf("%zd\n",sizeof(char));
   //printf("%zd\n",sizeof(long int));
   //printf("%zd\n",sizeof(long long int));
   //printf("%zd\n",sizeof(double));
   //printf("%zd\n",sizeof(float));
  // sprintf(s,"%02d\n", 1);
  // sprintf(s,"%02d\n", 2);
  //  printf(s);
  
   //scanf("%d\n", &c);
   //scanf("%d ", &c);
   //scanf("%d\t", &c);
   printf("%d\n",isalpha(a));
   return 0;
}

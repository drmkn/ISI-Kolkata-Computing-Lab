#include<stdio.h>
struct student{
       char *name;
       int roll;
       char *program;
};//x,y,*ptr,students[40];


struct something{
       int x,*y,z;
};
struct somethingelse{
       int x,y,*z;
};


int main(){
    printf("%ld\n",sizeof(struct student));
    printf("%ld\n",sizeof(struct something));
    printf("%ld\n",sizeof(struct somethingelse));
    struct student x,y,*ptr,students[40];
    ptr=&x;
    //printf("%ld\n",sizeof(ptr));
    x.name = "Abc Xyz";
    x.roll =1;
    x.program = "MTCS";
    printf("%p\n",ptr);
    printf("%p\n",ptr+1);
    printf("%p\n",ptr+2);
    printf("%p\n",ptr+3);
    printf("%p\n",&(x.name));
    printf("%p\n",&(x.roll));
    printf("%p\n",&(x.program));


    return 0;
}

#include<stdio.h>
#include<string.h>
#define Buff_len 128 
int comma_stop(char a){
    if(a == ','){
        return 0;
    }
    else{return -1;}
}
typedef struct{
    char *roll;
    char *name;
    long long int phone;
    char *email;
    int marks[21];
}Student;
int main(){
    int N;scanf("%d",&N);
    int c;int i;int j = 0;
    char Buffer[Buff_len];int marks;
    Student Data[N];int course_count =0;
    for (i = 0; i < N; i++){
        while((c=getchar()) != '\n'){
            while(comma_stop(c) != 0){
                Buffer[j] = c;j++;
            }
            Buffer[j] = '\0';j = 0;
            Data[i].roll = (char *)malloc((strlen(Buffer)+1)*(sizeof(char)));
            strncpy(Data[i].roll,Buffer,strlen(Buffer)+1);

            c = getchar();
            while(comma_stop(c) != 0){
                Buffer[j] = c;j++;
            }
            Buffer[j] = '\0';j = 0;
            Data[i].name = (char *)malloc((strlen(Buffer)+1)*(sizeof(char)));
            strncpy(Data[i].name,Buffer,strlen(Buffer)+1);

            scanf("%d",Data[i].phone);

            c = getchar();
            while(((c=getchar()) != '\n')&&(comma_stop(c) != 0)){
                Buffer[j] = c;j++;
            }
            Buffer[j] = '\0';j = 0;
            Data[i].email = (char *)malloc((strlen(Buffer)+1)*(sizeof(char)));
            strncpy(Data[i].email,Buffer,strlen(Buffer)+1);            
    }
    for(i = 0;i<N;i++){
        scanf("%s",Buffer);
        for(j = 0;j<N;j++){
            if(strcmp(Buffer,Data[i].roll) == 0){
                while()
            }

        }
    }
    }


    return 0; 
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Buff_len 128 
int comma_stop(char a){
    if(a == ','){
        return 0;
    }
    else{return -1;}
}
typedef struct{
    char roll[6];
    char name[Buff_len];
    long long int phone;
    char email[Buff_len];
    int marks[21];
}Student;
int main(){
    int N;scanf("%d",&N);
    int c;int i;int j = 0;int k = 0;
    char Buffer[Buff_len];int marks;
    Student Data[N];int course_count = 0;
    Student temp;
    for (i = 0; i < N; i++){
        //while((c=getchar()) != '\n'){
            //while(comma_stop(c) != 0){
             //   Buffer[j] = c;j++;
            //}
            //Buffer[j] = '\0';j = 0;printf("1");
            //Data[i].roll = (char *)malloc((strlen(Buffer)+1)*(sizeof(char)));
            //strcpy(Data[i].roll,Buffer,strlen(Buffer)+1);
            scanf("%s",Data[i].roll);

            c = getchar();
            //while(comma_stop(c) != 0){
            //    Buffer[j] = c;j++;
           // }
           // Buffer[j] = '\0';j = 0;
           // Data[i].name = (char *)malloc((strlen(Buffer)+1)*(sizeof(char)));
            //strncpy(Data[i].name,Buffer,strlen(Buffer)+1);
            scanf("%s",Data[i].name);
            c = getchar();
            scanf("%ld",Data[i].phone);

            c = getchar();
            //while(((c=getchar()) != '\n')&&(comma_stop(c) != 0)){
             //   Buffer[j] = c;j++;
            //}
            //Buffer[j] = '\0';j = 0;
            //Data[i].email = (char *)malloc((strlen(Buffer)+1)*(sizeof(char)));
            //strncpy(Data[i].email,Buffer,strlen(Buffer)+1);  
            scanf("%s",Data[i].email);     }     
   // }
    for(i = 0;i<N;i++){
        scanf("%s",Buffer);
        for(j = 0;j<N;j++){
            if(strcmp(Buffer,Data[j].roll) == 0){
                while((c=getchar()) != '\n'){
                    scanf("%d",&Data[j].marks[k+1]);k++;course_count++;
                }
                Data[j].marks[0] = course_count;k=0;course_count=0;
                break;
            }
            else{continue;}

        }
    }

    //sorting
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(strcmp(Data[i].roll,Data[j].roll) > 0){
                Data[i] = temp;
                Data[i] = Data[j];
                Data[j] = temp;
            }
            else{continue;}
        }
    }

    for(i=0;i<N;i++){
        for(j=0;j<Data[i].marks[0];j++){
            if(Data[i].marks[j+1] < 35){
                printf("%s\n",Data[i].email);break;
            }
            else{continue;}
        }

    }

    


    return 0; 
}

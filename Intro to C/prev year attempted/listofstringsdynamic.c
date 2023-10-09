#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int size;
    char **array;
} LIST;

LIST create_list(void){
    LIST L;
    L.size = 0;
    L.array = (char **) malloc(L.size*sizeof(char *));
    return L;
}

void print_list(LIST L){
     int i= 0;
     int j =0;
     char k;
     for(;i<L.size;i++){
        j = 0;
        while((j<9)&&((k=L.array[i][j]) != '\0')){
            printf("%c",k);
            j++;
        }
        printf("\n");
     }
}

LIST append(LIST L, char *a){
     L.size += 1;
     L.array = (char **) realloc(L.array,L.size*sizeof(char *));
     L.array[L.size-1] = a;
    return L;
}

LIST prepend(LIST L, char *a){
     L.size += 1;
     L.array = (char **) realloc(L.array, L.size*sizeof(char *));
     int i = 0;
     int j = 0;
     char k;
     for(;i<L.size-1;i++){
         L.array[L.size-i-1] = L.array[L.size-i-2];
     }
     L.array[0] = a;
    
     return L;   

}

LIST deletelast(LIST L){
    free(L.array[L.size-1]);
    L.size -= 1;
    L.array = (char **) realloc(L.array,L.size*sizeof(char *));
    return L;
}

LIST deletefirst(LIST L){
     free(L.array[0]);
     for(int i=1;i<L.size;i++){
        L.array[i-1] = L.array[i];
     }
     L.size--;
     return L;
}

LIST deleteall(LIST L, char *a){
    char **b;
    int flag  = 0;
    b = (char **) malloc(L.size*sizeof(char *));
    int a_count = 0;
    int i = 0;
    for(;i<L.size;i++){
        if(strcmp(L.array[i],a) != 0){
            b[i-a_count] = L.array[i];
        }
        else{a_count++;}
    }
    L.size -= a_count;
    L.array = (char **) malloc(L.size*sizeof(char *));
    for(i=0;i<L.size;i++){L.array[i]=b[i];}
    free(b);
    return L;
}



int main(){
    LIST L;

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct{
        int size;
        int *array;
       // array = (int*)malloc(size*sizeof(int));
       // if(NULL == array){
        //  printf("NULL");}
} LIST; 

LIST create_list(void){
    LIST L;
    L.size = 0;
    L.array = (int*)malloc(L.size*sizeof(int));
    return L;

}

void print_list(LIST L){
    int i = 0;
    for(;i<L.size;i++) printf("%d ",*(L.array + i));
    printf("\n");

}

LIST append(LIST L, int a){
       L.size += 1;
       L.array = (int*)realloc(L.array,L.size*sizeof(int));
       *(L.array+L.size-1) = a;
       return L;

}

LIST prepend(LIST L, int a){
       int *b;
       int i = 0;
       b = (int*)malloc(L.size*sizeof(int));
       for(;i<L.size;i++){
          *(b + i) = *(L.array+i);
       }
       L.size += 1;
       L.array = (int*)malloc(L.size*sizeof(int));
       for(i=1;i<L.size;i++){
          *(L.array+i) = *(b+i-1);
       }
       *(L.array) = a;
       free(b);
       return L;


}

LIST deletelast(LIST L){
     L.size -= 1;
     L.array = (int*)realloc(L.array,L.size*sizeof(int));  
     return L;
}

LIST deletefirst(LIST L){
     int *b;
     int i = 1;
     b = (int*)malloc(L.size*sizeof(int));
     for(;i<L.size;i++){
          *(b+i-1) = *(L.array+i);
       }
     L.size -= 1;
     L.array = (int*)malloc(L.size*sizeof(int)); 
     for(i=0;i<L.size;i++){
          *(L.array+i) = *(b+i);
       }
     free(b);  
     return L;  
}

LIST deleteall(LIST L, int a){
     int *b;
     int i = 0;
     int count_a = 0;
     b = (int*)malloc(L.size*sizeof(int));
     for(;i<L.size;i++){
        if(*(L.array+i) != a){
           *(b+i-count_a) = *(L.array+i);
        
        }
        else{count_a++;}
     }
     L.size -= count_a;
     L.array = (int*)malloc(L.size*sizeof(int)); 
     for(i=0;i<L.size;i++){
          *(L.array+i) = *(b+i);
       }
     free(b);
     return L;

}


int main(){
    LIST A;
    int i = 0;
    A = create_list();
    print_list(A);
    A = append(A,2);
    print_list(A);
    A = prepend(A,8); 
    print_list(A);
    A = deletefirst(A);
    print_list(A);
    A = append(A,9); 
    print_list(A);
    A = append(A,3);
    print_list(A);
    A = prepend(A,9);
    print_list(A);
    A = deletefirst(A);
    print_list(A);
    A = append(A,1);
    print_list(A); 
    A = prepend(A,9);
    print_list(A);
    A = prepend(A,1);
    print_list(A);
    A = deletefirst(A);
    print_list(A);
    A = append(A,2);
    print_list(A); 
    A = prepend(A,2);
    print_list(A); 
    A = deletelast(A);
    print_list(A);
    A = deletefirst(A);
    print_list(A);
    A = append(A,3);
    print_list(A); 
    A = prepend(A,4);
    print_list(A);
    A = deletelast(A);
    print_list(A); 
    A = deleteall(A,7);
    print_list(A);
    A = append(A,6);
    print_list(A);
    A = prepend(A,8);
    print_list(A);
    A = deletelast(A);
    print_list(A);
    A =  deleteall(A,2);
    print_list(A);
    A = append(A,7);
    print_list(A);
    A = prepend(A,2);
    print_list(A); 
    A = deletelast(A);
    print_list(A);
    A = deleteall(A,9);
    print_list(A);
    A = append(A,8);
    print_list(A);
    A = prepend(A,5);
    print_list(A);
    A = deletelast(A);
    print_list(A); 
    A = deleteall(A,4);
    print_list(A);
    A = append(A,4);
    print_list(A);
    A = prepend(A,9);
    print_list(A);
    A = deletefirst(A);
    print_list(A); 
    A = deleteall(A,7);
    print_list(A);
    //printf("%d\n",A.size);
    //for(i=0;i<A.size;i++) printf("%d",*(A.array+i));
    //printf("\n");




    return 0;
}






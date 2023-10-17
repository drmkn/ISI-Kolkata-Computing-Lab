#include<stdio.h>
#include "list.h"

int main(){
    LIST L;
    L = init_list();
    //printf("%d",L.head->d);
    insert(&L,1,1);insert(&L,3,0);insert(&L,2,1);insert(&L,-1,2);
    //printf("%d",L.tail->prev->d);
    //print_list(&L);
    //printf("%d",L.num_elements);
    //printf("%d",r);

    return 0;
}
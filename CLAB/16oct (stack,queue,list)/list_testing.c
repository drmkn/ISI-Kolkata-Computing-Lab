#include<stdio.h>
#include "list.h"

int main(){
    LIST L;
    DATA value;
    L = init_list();
    //printf("%d",L.head->d);
    insert(&L,3,0);insert(&L,2,1);insert(&L,3,2);//delete(&L,&value,0);
    //printf("%d",L.tail->prev->d);
    //print_list(&L);
    //printf("%d",L.num_elements);
    //printf("%d",r);
    printf("%d",find_value(&L,4));

    return 0;
}
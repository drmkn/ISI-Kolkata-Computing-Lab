#include<stdio.h>
#include<stdlib.h>
#include "list.h"

LIST init_list(){
    LIST L;
    L.num_elements = 0;
    L.head = (DATA*)malloc(L.num_elements*sizeof(NODE));
    L.tail = L.head;
    return L;
}

int insert(LIST *l, DATA d, unsigned int index){
    
}
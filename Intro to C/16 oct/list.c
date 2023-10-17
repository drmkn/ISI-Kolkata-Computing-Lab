#include<stdio.h>
#include<stdlib.h>
#include "list.h"

LIST init_list(){
    LIST L;
    L.num_elements = 0;
    L.head = NULL;
    L.tail = NULL;
    //L.head->prev = NULL;L.tail->next = NULL;
    return L;
}

int insert(LIST *l, DATA d, unsigned int index){
    NODE *temp,*new_node;
    temp = l->head;
    if((index < l->num_elements) && (index > 0)){
        for(int i = 0;i<index-1;i++){
            temp = temp->next;
        }
        new_node = (NODE*)malloc(1*sizeof(NODE));l->num_elements++;
        new_node->d = d;new_node->prev = temp;new_node->next = temp->next;
        temp->next=new_node;(temp->next->next)->prev = new_node;
    }
    else if(index == 0){
        if(l->head != NULL){
            new_node = (NODE*)malloc(1*sizeof(NODE));l->num_elements++;
            new_node->d = d;new_node->prev = NULL;
            new_node->next = temp;temp->prev = new_node;
            l->head = new_node;        
        }
        else{
            new_node = (NODE*)malloc(1*sizeof(NODE));l->num_elements++;
            new_node->d = d;new_node->prev = NULL;new_node->next = NULL;
            l->head = new_node;l->tail = new_node;
        }
    }
    else if(index == l->num_elements){
        new_node = (NODE*)malloc(1*sizeof(NODE));l->num_elements++;
        new_node->d = d;new_node->prev = l->tail;l->tail->next = new_node;
        new_node->next = NULL;l->tail = new_node;
    }
    else if(index > l->num_elements){
        printf("index out of range ");
        return 0;
    }
    return 1;

}

void print_list(LIST *l){
    NODE *temp;
    temp = l->head;
    if(temp == NULL){
        printf("Empty List");
    }
    else{printf("%d ",temp->d);
        while((temp = temp->next) != NULL){
           printf("%d ",temp->d); 
            }
    }
}

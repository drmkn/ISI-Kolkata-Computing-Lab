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

int delete(LIST *l, DATA *d, unsigned int index){
    NODE *temp,*temp1;
    temp = l->head;

    if((index < l->num_elements) && (index > 0)){
        for(int i = 0; i<index-1; i++){
            temp = temp->next;
        }
        temp1 = temp->next; //temp1 node is to be deleted
        if(temp1->next != NULL){
            temp->next = temp1->next;
            temp1->next->prev = temp;*d = temp1->d;
            free(temp1);l->num_elements--;}
        else{ //temp1 is tail
            *d = temp1->d;free(temp1);l->num_elements--;
            temp->next = NULL;l->tail = temp;
        }    
    }
    else if(index == 0){
        NODE *temp;
        temp = l->head;
        l->head = temp->next;l->head->prev = NULL;*d = temp->d;
        free(temp);l->num_elements--;
    }
    else if(index >= l->num_elements){
        printf("index out of range");
        return 0;
    }
    
    return 1;
}

int find_index(LIST *l, DATA d){
    NODE *temp;temp = l->head;
    int count = 0;
    if(l->num_elements > 0){
        while((temp->next != NULL) && (temp->d != d)){
            temp = temp->next;count++;
        }
        if(count+1 == l->num_elements){
            printf("not found ");
        }
        else{
        return count;}
    }
    else if(l->num_elements == 0){
        printf("Empty list ");
        return -1;
    } 
    return -1;   

}

DATA find_value(LIST *l, unsigned int index){
    NODE *temp;temp = l->head;
    if((index > 0) && (index < l->num_elements)){
        for(int i = 0; i<index; i++){
            temp = temp->next;
        }
        return temp->d;
    }
    else if(index == 0){
        return temp->d;
    }
    else if(index > l->num_elements){
        printf("index out of range");
    }
    return -1;
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

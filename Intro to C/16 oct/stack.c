#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

STACK create_stack(unsigned int capacity){
    STACK S;
    S.capacity = capacity;
    if(NULL == (S.elements = (DATA *)malloc(capacity*sizeof(DATA)))){
        fprintf(stderr,"Error"); //remember to use fprintf through stderr
        exit(1);
    }
    S.elements = (DATA *)malloc(capacity*sizeof(DATA));
    S.top = -1;
    return S;
}

void push(STACK *s, DATA d){
    //int n = s->top; 
    if(s->top != s->capacity-1){
        s->top++; 
        s->elements[s->top] = d;
    }
    else{
        s->elements = (DATA *)realloc(s->elements,2*s->capacity*sizeof(DATA));
        s->top++;
        s->elements[s->top] = d;
    }

}

DATA pop(STACK *s, DATA *d){
    if(s->top != -1){
     *d = s->top--;
    }
    else{
        printf("STACK is already empty");
        return 1;
    }
    if(s->top < s->capacity){
       s->elements = (DATA *)realloc(s->elements,0.5*s->capacity*sizeof(DATA)); 
    }
    return 1;
}

void print_stack(STACK *s){
    for(int i = 0;i<=s->top;i++){
        printf("%d",s->elements[i]);
    }
}
#include "stack.h"
#include "stdio.h"

int main(){
    STACK S;DATA temp;
    S = create_stack(4);
    push(&S,1);
    push(&S,2);push(&S,1);push(&S,0);
    pop(&S,&temp);
    push(&S,3);push(&S,3);
    print_stack(&S);
    printf("\n%d",temp);



    return 0;
}
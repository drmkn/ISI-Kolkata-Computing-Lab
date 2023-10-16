#include "stack.h"

int main(){
    STACK S;
    S = create_stack(4);
    push(&S,1);
    push(&S,2);push(&S,1);push(&S,0);
    //pop(&S);
    push(&S,3);push(&S,3);
    print_stack(&S);



    return 0;
}
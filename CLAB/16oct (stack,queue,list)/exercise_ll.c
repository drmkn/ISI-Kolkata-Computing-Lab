#include "common.h"
typedef struct _node {
      int x;
      int y;
      struct _node *nextx;
      struct _node *nexty;
   } node;

typedef node *list;

list genRandlist(int n){
    node *n1,*n2;
    list L;
    //dummy node//
    L = (list)malloc(sizeof(node));
    L->x = L->y=0;
    L->nextx = L->nexty = NULL;
    int j;
    n1 = L;
    for(j=0;j<n;j++){
        n2 = Malloc(1,node);
        n2->x = 1000 + rand() % 9000;
        n2->y = 1000 + rand() % 9000;
        n1->nextx = n1->nexty = n2;
        n2->nextx = n2->nexty = NULL;
        n1 = n2;
    }
    //(L+n-1)->nextx = (L+n-1)->nexty = NULL;

    return L;
}

void print_ll(list L, int flag ){
    node *nptr;
    nptr = L;
    if(flag == 0){
        while(nptr){
            printf("%d ",nptr->x);
            nptr = nptr->nextx;
        }
    }
    else{
        while(nptr){
            printf("%d ",nptr->y);
            nptr = nptr->nexty;
        }
    }
    return;
}

void bubbleSortX ( list L ){
    int flag = 0;
    int i;int length;
    node *n1,*n2,*n3,*n4,*temp;
    n1 = L;
    while(n1->nextx){
        length++;
    }
    n1 = NULL;
    n2 = L;n3 = n2->nextx;
    n4 = n3->nextx;
    for(i=0;i<length-1;i++){
        while(n3){
            if(n2->x > n3->x){
                n1->nextx = n3;
                n3->nextx = n2;
                n2->nextx = n4;
            }
            n2 = n2->nextx;n3 = n3->nextx;n4 = n4->nextx; 
        }
    }


}


int main(){
    list l;
    l = genRandlist(10);




    return 0;
}
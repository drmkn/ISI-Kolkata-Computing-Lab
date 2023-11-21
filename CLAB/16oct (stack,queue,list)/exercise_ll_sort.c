#include "common.h"
#define N 100
#define WRT_X 0
#define WRT_Y 1
typedef struct _node {
      int x;
      int y;
      struct _node *nextx;
      struct _node *nexty;
   } node;

typedef node *list;

list genRandList(int n){
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

void printList(list L, int flag ){
    node *nptr;
    nptr = L;
    if(flag == 0){
        while(nptr){
            printf("%d ",nptr->x);
            nptr = nptr->nextx;
        }
        putchar('\n');
    }
    else{
        while(nptr){
            printf("%d ",nptr->y);
            nptr = nptr->nexty;
        }
        putchar('\n');
    }
    return;
}

void bubbleSortX(list L){
    int flag = 0;
    int i,j;int length = 0;
    node *prev,*curr,*next;
    curr = L->nextx;prev = L;next = curr->nextx;
    while(curr){
        length++;curr = curr->nextx;
    }
    curr = L->nextx;
    for(i=0;i<length-1;i++){
        //if(flag == length) break;
        j=0;prev = L;curr = prev->nextx;next = curr->nextx;
        while(j<length-i-1){
            if(curr->x > next->x){       
                curr->nextx = next->nextx;
                next->nextx = curr;
                prev->nextx = next;
                prev = next;next = curr->nextx;//flag=0;
                }
            else{
                prev = curr;
                curr = next;
                next = curr->nextx;
                //flag++;
            }
            j++;    
            } 
        }
}

void bubbleSortY(list L){
    int flag = 0;
    int i,j;int length = 0;
    node *prev,*curr,*next;
    curr = L->nexty;prev = L;next = curr->nexty;
    while(curr){
        length++;curr = curr->nexty;
    }
    curr = L->nexty;
    for(i=0;i<length-1;i++){
        j=0;prev = L;curr = prev->nexty;next = curr->nexty;
        while(j<length-i-1){
            if(curr->y > next->y){       
                curr->nexty = next->nexty;
                next->nexty = curr;
                prev->nexty = next;
                prev = next;next = curr->nexty;//flag=0;
                }
            else{
                prev = curr;
                curr = next;
                next = curr->nexty;
                //flag++;
            }
            j++;    
            } 
        }
}




int main ()
   {
      list L;

      L = genRandList(N);
      printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
      printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
      bubbleSortX(L);
      bubbleSortY(L);
      printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
      printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
      exit(0);
   }

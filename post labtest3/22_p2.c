#include "common.h"

#define INIT_HEAP_SIZE 100

typedef struct node {
    int d;
    struct node *next;
} NODE;
typedef struct {
    unsigned int num_elements;
    NODE *head;
} LIST;

NODE *create_node(int d){
    NODE *nptr = Malloc(1,NODE);
    nptr->d = d;nptr->next = NULL;
    return nptr;
}
LIST *create_list(){
    LIST *L = Malloc(1,LIST);
    L->head = NULL;L->num_elements = 0;
    return L;
}
typedef struct {
    size_t element_size; /* generic => need to store this */
    unsigned int num_allocated, num_used;
    void *array;         /* one-based indexing used (cf. SEDGEWICK AND WAYNE) */
    int (*comparator)(void *, int, int); /* returns -ve, 0, or +ve, as for qsort */
} HEAP;


void initHeap(HEAP *h, size_t element_size, int (*comparator)(void *, int, int));
void insert(HEAP *h, void *x);
void deleteMin(HEAP *h, void *min);
void buildheap(HEAP *h);
void heapsort(void *a, int N, size_t element_size, int (*comparator)(void *, int, int));



void initHeap(HEAP *h, size_t element_size, int (*comparator)(void *, int, int)) {
    h->element_size = element_size;
    h->num_allocated = 10;
    h->num_used = 0;
    if (NULL == (h->array = malloc(h->num_allocated * element_size))) {
        perror("initHeap: out of memory");
        exit(-1);
    }
    h->comparator = comparator;
    return;
}


static void swap(HEAP *h, int i, int j)
{
    /* NOTE: One-based indexing is used. h->array[0] is unused and 
     * can be used as the temporary location while swapping
     */
    char *ip = (char *) h->array + i * h->element_size;
    char *jp = (char *) h->array + j * h->element_size;
    char *tp = (char *) h->array;
    memcpy((void *) tp, (void *) ip, h->element_size);
    memcpy((void *) ip, (void *) jp, h->element_size);
    memcpy((void *) jp, (void *) tp, h->element_size);
    return;
}


static void swapUp(HEAP *h, int k)
{
    while (k > 1 && (h->comparator(h->array, k/2, k) < 0)) {
        swap(h, k, k/2);
        k = k/2;
    }
    return;
}

void insert(HEAP *h, void *x)
{
    /* First, make sure there's space for another element */
    if (h->num_used + 1 == h->num_allocated) {
        h->num_allocated *= 2;
        if (NULL == (h->array = realloc(h->array, h->num_allocated * h->element_size))) {
            perror("insert: out of memory");
            exit(-1);
        }
    }
    /* Insert element at end */
    h->num_used++;
    memcpy((char *) h->array + h->num_used * h->element_size,
           x,
           h->element_size);
    /* Restore heap property */
    swapUp(h, h->num_used);
    return;
}


static void swapDown(HEAP *h, int k)
{
    while (2*k <= h->num_used) {
        int j = 2*k;
        /* choose child with larger key */
        if (j < h->num_used && (h->comparator(h->array, j, j+1) < 0))
            j++;
        if (h->comparator(h->array, k, j) >= 0) break;
        swap(h, k, j);
        k = j;
    }
    return;
}

void deleteMin(HEAP *h, void *min)
{
    /* Max is at the root (index 1) */
    memcpy(min, h->array + h->element_size, h->element_size);
    /* Copy last element to root */
    memcpy(h->array + h->element_size,
           h->array + h->num_used * h->element_size,
           h->element_size);
    h->num_used--;
    /* Restore heap property */
    swapDown(h, 1);
    return;
}

void buildheap(HEAP *h)
{
    int k;

    for (k = h->num_used / 2; k >= 1; k--)
        swapDown(h, k);
    return;
}

void heapsort(void *a, int N, size_t element_size, 
              int (*comparator)(void *, int, int))
{
  HEAP h;

  h.element_size = element_size;
  h.num_allocated = h.num_used = N;
  h.array = a;
  h.comparator = comparator;
  /* Make heap out of array */
  buildheap(&h);
  /* Sort by successive deleteMax */
  while (h.num_used > 1) {
      swap(&h, 1, h.num_used); // move max to end
      h.num_used--;
      swapDown(&h, 1);
  }

  return;
}

static int compare_int(void *array, int i1, int i2)
{
    int n1 = *((int *) array + i1);
    int n2 = *((int *) array + i2);
    return n2 - n1;
}


int main(int ac, char *av[])
{   
    int k,n;scanf("%d",&k);int sizes[k];
    LIST **L = Malloc(k,LIST*);
    for(int i = 0;i<k;i++){
        scanf("%d",&sizes[i]);
        n += k;
        NODE *nptr; int d;
        L[i] = create_list();
        for(int j = 0;j<sizes[i];j++){
            scanf("%d",&d);
            if(j==0){
                L[i]->head = create_node(d);
                nptr = L[i]->head;nptr->next = NULL;
            }
            else{
                nptr->next = create_node(d);
                nptr = nptr->next;nptr->next = NULL;
            }
        }
    }
    HEAP H;initHeap(&H,sizeof(int),compare_int);
    int min,i,j;NODE** nptrs = Malloc(k,NODE*);
    for(i = 0;i<k;i++){nptrs[i] = L[i]->head;insert(&H,&nptrs[i]->d);}
    while(H.num_used != 0){
        deleteMin(&H,&min);printf("%d ",min);
        for(j = 0;j<k;j++){
            if(NULL != nptrs[j] && min == nptrs[j]->d){
                nptrs[j] = nptrs[j]->next;break;
            }
            else continue;
        }
        if(NULL == nptrs[j]) continue;
        else insert(&H,&nptrs[j]->d); 
    }
    free(L);
    

    return 0;
}

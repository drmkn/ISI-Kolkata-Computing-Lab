#ifndef _HEAP_H_
#define _HEAP_H_

#define INIT_HEAP_SIZE 100

typedef struct {
    size_t element_size; /* generic => need to store this */
    unsigned int num_allocated, num_used;
    void *array;         /* one-based indexing used (cf. SEDGEWICK AND WAYNE) */
    int (*comparator)(void *, int, int); /* returns -ve, 0, or +ve, as for qsort */
} HEAP;


void initHeap(HEAP *h, size_t element_size, int (*comparator)(void *, int, int));
void insert(HEAP *h, void *x);
void deleteMax(HEAP *h, void *max);
void buildheap(HEAP *h);
void heapsort(void *a, int N, size_t element_size, int (*comparator)(void *, int, int));



#endif // _HEAP_H

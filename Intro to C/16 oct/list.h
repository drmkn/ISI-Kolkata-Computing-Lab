#ifndef LIST_H
#define LIST_H
typedef int DATA;

typedef struct node{
    DATA d;
    struct node *next, *prev;   
}NODE;

typedef struct{
    NODE *head, *tail;
    unsigned int num_elements;
}LIST;

extern LIST init_list();
extern int insert(LIST *l, DATA d, unsigned int index);
extern int delete(LIST *l, DATA *d, unsigned int index);
extern DATA find_index(LIST *l, DATA d);
extern DATA find_value(LIST *l, unsigned int index);
extern void print_list(LIST *l);










#endif
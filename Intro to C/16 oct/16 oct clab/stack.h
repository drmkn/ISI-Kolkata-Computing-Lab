#ifndef STACK_H
#define STACK_H

typedef int DATA; // Also try typedef char * DATA;
typedef struct {
int capacity, top;
DATA *elements;
} STACK;

extern STACK create_stack();
extern void push(STACK *s, DATA d);
extern DATA pop(STACK *s);
extern void print_stack(STACK *s);

#endif
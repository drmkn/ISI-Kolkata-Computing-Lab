#ifndef BST_H
#define BST_H

#include <time.h>

typedef int DATA;
typedef struct node{
    DATA data;
    struct node *left, *right;
}BSTNODE;

extern int compare(BSTNODE *n, DATA d);
extern void inorder(BSTNODE *root);
extern void print_tree(BSTNODE *root, int indent);
extern void print_pstree(BSTNODE *root);
extern BSTNODE *search(BSTNODE *root, DATA d);
extern BSTNODE *detach_successor(BSTNODE *node);

#endif /* BST_H */

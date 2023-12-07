#include <time.h>
#include "common.h"
typedef int DATA;

typedef struct node{
    DATA data;
    struct node *left, *right;
}BSTNODE;

BSTNODE *insert(BSTNODE *root, DATA d);
int compare(BSTNODE *n, DATA d);
void inorder(BSTNODE *root);
void preorder(BSTNODE *root);
void postorder(BSTNODE *root);
//void print_tree(BSTNODE *root, int indent);
//void print_pstree(BSTNODE *root);
BSTNODE *search(BSTNODE *root, DATA d);
BSTNODE *detach_successor(BSTNODE *node);
void delete(BSTNODE **nodeptr, DATA d);

BSTNODE *insert(BSTNODE *root, DATA d){
    /* Base case */
    if(NULL == root){
        root = Malloc(1, BSTNODE); /* should check return value */
        root->data = d;
        root->left = root->right = NULL;
        return root;
    }
    /* Recurse */
    int cmp = compare(root, d);
    if(cmp < 0)
        root->left = insert(root->left, d);
    else if(cmp > 0)
        root->right = insert(root->right, d);
    return root;
    }

int compare(BSTNODE *n, DATA d){
    if(n->data == d) return 0;
    else if(n->data > d) return -1;
    else return 1;
}

BSTNODE *search(BSTNODE *root, DATA d){
    if(root == NULL)
        return NULL;
    int cmp = compare(root, d);
    if(cmp < 0)
        return search(root->left, d);
    else if(cmp > 0)
        return search(root->right, d);
    else
        return root;
}

void delete(BSTNODE **nodeptr, DATA d){
    BSTNODE *node, *s;
    assert(nodeptr != NULL);
    node = *nodeptr;
    if(node == NULL)
        return;
    int cmp = compare(node, d);
    if(cmp < 0)
        delete(&(node->left), d);
    else if(cmp > 0)
        delete(&(node->right), d);
    else{
        if(node->left == NULL && node->right == NULL){
        /* Case I: leaf, just delete */
        *nodeptr = NULL;
        free(node);
        return;
        }
        /* Case II: only one child (no left child) */
        if(node->left == NULL){
            *nodeptr = node->right;
            free(node);
            return;
        }
        /* Case II: only one child (no right child) */
        if(node->right == NULL){
            *nodeptr = node->left;
            free(node);
            return;
        }
        /* Case III: both sub-trees present */
        s = detach_successor(node);
        node->data = s->data;
        free(s);
        }
    return;
}


BSTNODE *detach_successor(BSTNODE *node){
    BSTNODE *nptr;
    assert(node != NULL);
    /* Go to right child, then as far left as possible */
    nptr = node->right;
    if(nptr == NULL) /* no successors */
        return NULL;
    if(nptr->left == NULL){
        node->right = nptr->right;
        return nptr;
    }
    while(nptr->left != NULL){
        node = nptr;
        nptr = nptr->left;
    }
    node->left = nptr->right;
    return nptr;
}

void preorder(BSTNODE *root){
    if(NULL == root){// Reached a leaf node
        printf("%c ",'l');
        return;}
    // Visit the node
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(BSTNODE *root){
    if(NULL == root){ // Reached a leaf node
        printf("%c ",'l');
        return;}
    // Visit the node
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(BSTNODE *root){
    if(NULL == root){ // Reached a leaf node
        printf("%c ",'l');
        return;}
    // Visit the node
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}



int main(){
    BSTNODE *T = NULL;int data;
    //T = NULL;
    for(int i = 0; i < 10; i++){
        data = rand() % 100;
        T = insert(T, data);
    }
    //T = insert(T,4);T = insert(T,3);T = insert(T,2);
    preorder(T);putchar('\n');
    delete(&T,86);
    preorder(T);putchar('\n');
    //postorder(T);putchar('\n');
    //T = search(T,93);
    //printf("%d",T->data);
    return 0;
}
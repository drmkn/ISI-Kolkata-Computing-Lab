#include<time.h>
#include "common.h"
typedef int DATA;

typedef struct node{
    DATA A[2];
    DATA span[2];
    int left, right;
}BSTNODE;

typedef struct{
    unsigned int max_nodes;
    int root;
    BSTNODE *nodelist;
}TREE;

TREE *init(TREE *T,int max_nodes);
int insert(TREE *T, DATA d);
int compare(TREE *T,int root,DATA d);
void preorder(TREE *, int root);
void inorder(TREE *T, int root);
void postorder(TREE *T, int root);
void print_pstree(TREE*, int root);
int search(TREE *T, DATA d);
int detach_successor(TREE *, int node);

TREE *init(TREE *T,int max_nodes){
    T = Malloc(1,TREE);
    T->max_nodes = max_nodes;
    T->nodelist = Malloc(T->max_nodes,BSTNODE);T->root = -1;
    for(int i = 0;i<T->max_nodes;i++){
        T->nodelist[i].left = T->nodelist[i].right = -1;
    }
    return T;
}

void span_creator(TREE *T, int root){
    if(-1 == root){// Reached a leaf node
        return;}
    // Visit the node
    BSTNODE *node = T->nodelist+root;
    span_creator(T,node->left);
    span_creator(T,node->right);
    if(node->left == -1 & node->right == -1){
        node->span[0] = node->A[0];node->span[1] = node->A[1];return;
    }
    else if(node->left == 1 & node->right == -1){
        node->span[0] = MIN(T->nodelist[node->left].span[0],node->A[0]);
        node->span[1] = MAX(T->nodelist[node->left].span[1],node->A[1]);
        return;
    }
    else if(node->left == -1 & node->right == 1){
        node->span[0] = MIN(T->nodelist[node->right].span[0],node->A[0]);
        node->span[1] = MAX(T->nodelist[node->right].span[1],node->A[1]);
        return;
    }
    else{
        int p,q;
        p = MIN(T->nodelist[node->left].span[0],T->nodelist[node->right].span[0]);
        q = MAX(T->nodelist[node->left].span[1],T->nodelist[node->right].span[1]);
        node->span[0] = MIN(p,node->A[0]);node->span[1] = MAX(q,node->A[1]); 
        return;
    }
    
}


int main(){
    int n,c;scanf("%d",&n);TREE *T;int flag_root = 0;
    T = init(T,n+1);BSTNODE *node;
    for(int i = 0;i<n;i++){
        node = T->nodelist+i;
            if(flag_root == 0){
                scanf("%d",&node->A[0]);scanf("%d",&node->A[1]);
                scanf("%d",&node->left);scanf("%d",&node->right);
                T->root = 0;flag_root++;
            }
            else{
                scanf("%d",&node->A[0]);scanf("%d",&node->A[1]);
                scanf("%d",&node->left);scanf("%d",&node->right);
            }   
        }
    span_creator(T,T->root);putchar('\n');
    for(int i = 0;i<n;i++){
        node = T->nodelist+i;
        printf("%d %d %d %d\n",node->span[0],node->span[1],node->left,node->right);
    }



    return 0;
}
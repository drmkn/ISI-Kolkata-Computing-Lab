#include<time.h>
#include "common.h"
typedef int DATA;

typedef struct node{
    DATA data;
    int left, right;
}BSTNODE;

typedef struct{
    unsigned int num_nodes, max_nodes;
    int root, free_list;
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
    T->nodelist = Malloc(T->max_nodes,BSTNODE);T->root = -1;T->free_list = 0;
    for(int i = 0;i<T->max_nodes;i++){
        T->nodelist[i].data = T->nodelist[i].left = T->nodelist[i].right = -1;
    }
    return T;
}

int insert(TREE *T, DATA d){
    int nearest_index = search(T,d);
    if(T->root == -1){
        T->root = T->free_list++;T->nodelist[T->root].data = d;T->num_nodes++;
        return 1;
    }
    if(nearest_index == -1){
        T->nodelist[T->free_list++].data = d;T->num_nodes++;
        return 1;
    }
    if(compare(T,nearest_index,d)<0){
        T->nodelist[T->free_list].data = d;
        T->nodelist[nearest_index].left = T->free_list++;T->num_nodes++;
        return 1; 
    }
    else if(compare(T,nearest_index,d)>0){
        T->nodelist[T->free_list].data = d;//T->free_list++;
        T->nodelist[nearest_index].right = T->free_list++;T->num_nodes++;
        return 1; 
    }
    else return -1;
    }


int compare(TREE *T,int root,DATA d){
    if(T->nodelist[root].data == d) return 0;
    else if(T->nodelist[root].data > d) return -1;
    else return 1;
}

int search(TREE *T, DATA d){
    if(T->root == -1) return -1; //empty tree
    int index = T->root;int oldindex = T->root;
    while(index != -1){
        if(compare(T,index,d)>0){
            oldindex = index;
            index = T->nodelist[index].right;
        }
        else if(compare(T,index,d)<0){
            oldindex = index;
            index = T->nodelist[index].left;
        }
        else{return index;}
        if(index == -1){return oldindex;}
        else continue;
    } 
}

void preorder(TREE *T, int root){
    if(-1 == root){// Reached a leaf node
        printf("%c ",'l');
        return;}
    // Visit the node
    printf("%d ",T->nodelist[root].data);
    preorder(T,T->nodelist[root].left);
    preorder(T,T->nodelist[root].right);
}

void inorder(TREE *T, int root){
    if(-1 == root){// Reached a leaf node
        printf("%c ",'l');
        return;}
    // Visit the node
    inorder(T,T->nodelist[root].left);
    printf("%d ",T->nodelist[root].data);
    inorder(T,T->nodelist[root].right);
}

void postorder(TREE *T, int root){
    if(-1 == root){// Reached a leaf node
        printf("%c ",'l');
        return;}
    // Visit the node
    postorder(T,T->nodelist[root].left);
    postorder(T,T->nodelist[root].right);
    printf("%d ",T->nodelist[root].data);
}

int main(){
    TREE *T;T = init(T,256);/*insert(T,5);insert(T,7);insert(T,1); 
    printf("%d %d %d\n",T->nodelist->data,T->nodelist->left,T->nodelist->right);
    printf("%d %d %d\n",T->nodelist[1].data,T->nodelist[1].left,T->nodelist[1].right); 
    printf("%d %d %d\n",T->nodelist[2].data,T->nodelist[2].left,T->nodelist[2].right);
    printf("%d %d %d",search(T,5),search(T,7),search(T,1));
    */
    for(int i = 0; i < 5; i++){
        int data = rand() % 100;
        insert(T, data);
    }
    //preorder(T,T->root);putchar('\n');inorder(T,T->root);putchar('\n');postorder(T,T->root);
    //printf("%d",T->num_nodes);


    return 0;
}
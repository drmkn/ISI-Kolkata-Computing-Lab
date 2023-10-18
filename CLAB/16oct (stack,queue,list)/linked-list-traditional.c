#include "common.h"

#define MAX_VALUE 1000

typedef int DATA;
typedef struct node {
    DATA d;
    struct node *next, *prev;
} NODE;
typedef struct {
    unsigned int num_elements;
    NODE *head, *tail;
} LIST;

NODE *create_node(DATA d);
void init_list(LIST *l);
int insert(LIST *l, unsigned int index, DATA d);
int delete(LIST *l, unsigned int index, DATA *d);
int find_index(LIST *l, DATA d);
int find_value(LIST *l, unsigned int index, DATA *d);
void print_list(LIST *l);
void free_list(LIST *l);


NODE *create_node(DATA d) {
    NODE *nptr;
    if (NULL == (nptr = Malloc(1, NODE)))
        ERR_MESG("out of memory");
    nptr = (NODE*)malloc(1*sizeof(NODE));    
    nptr->d = d;
    nptr->next =nptr->prev =  NULL;
    return nptr;
}

void init_list(LIST *l) {
    l->num_elements = 0;
    l->head = l->tail = NULL;
    return;
}
    
int insert(LIST *l, unsigned int index, DATA d) {
    NODE *temp,*new_node;
    new_node = create_node(d);
    temp = l->head;
    //if(l->num_elements == 0){return -1;}
    if((index < l->num_elements) && (index > 0)){
        for(int i = 0;i<index-1;i++){
            temp = temp->next;
        }
        //new_node = (NODE*)malloc(1*sizeof(NODE));l->num_elements++;
        new_node->prev = temp;new_node->next = temp->next;
        temp->next=new_node;(temp->next->next)->prev = new_node;l->num_elements++;
        return 1;
    }
    else if((index == 0)){
        if(l->head != NULL){
            //new_node = (NODE*)malloc(1*sizeof(NODE));//l->num_elements++;
            //new_node->prev = NULL;
            new_node->next = temp;temp->prev = new_node;
            l->head = new_node;l->num_elements++;     
            return 1;   
        }
        else{
            //new_node = (NODE*)malloc(1*sizeof(NODE));//l->num_elements++;
            //new_node->prev = NULL;new_node->next = NULL;
            l->head = new_node;l->tail = new_node;l->num_elements++;
            return 1;
        }
    }
    else if(index == l->num_elements){
        //new_node = (NODE*)malloc(1*sizeof(NODE));l->num_elements++;
        new_node->prev = l->tail;l->tail->next = new_node;
        new_node->next = NULL;l->tail = new_node;l->num_elements++;
        return 1;
    }
    else if(index > l->num_elements){
        printf("index out of range ");
        return -1;
    }
    return -1;
   
}

int delete(LIST *l, unsigned int index, DATA *d) {
    NODE *temp,*temp1;
    temp = l->head;

    if((index < l->num_elements) && (index > 0)){
        for(int i = 0; i<index-1; i++){
            temp = temp->next;
        }
        temp1 = temp->next; //temp1 node is to be deleted
        if(temp1->next != NULL){
            temp->next = temp1->next;
            temp1->next->prev = temp;*d = temp1->d;
            free(temp1);l->num_elements--;return 1;}
        else{ //temp1 is tail
            *d = temp1->d;free(temp1);l->num_elements--;
            temp->next = NULL;l->tail = temp;return 1;
        }    
    }
    else if((index == 0) && (l->num_elements != 1)){
        NODE *temp;
        temp = l->head;
        l->head = temp->next;l->head->prev = NULL;*d = temp->d;
        free(temp);l->num_elements--;
        return 1;
    }
    else if((index >= l->num_elements) && (l->num_elements == 0) ){
        printf("index out of range");
        return -1;
    } else if (l->num_elements == 1){
        *d = l->head->d;
        free(l->head);l->head=NULL;l->tail=NULL;
        l->num_elements--;
        return 0;
    }
    
    return -1;
}

int find_index(LIST *l, DATA d) {
    NODE *temp;temp = l->head;
    int count = 0;
    if(l->num_elements > 0){
        while((temp->next != NULL) && (temp->d != d)){
            temp = temp->next;count++;
        }
        if(count+1 == l->num_elements){
            printf("not found ");
            return -1;
        }
        else{
        return count;}
    }
    else if(l->num_elements == 0){
        //printf("Empty list ");
        return 0;
    } 
    //return -1;   

}

int find_index_in_sorted(LIST *l, DATA d){
    NODE *temp;temp = l->head;
    int count = 0;
    if(l->num_elements == 0){return 0;}
    if(temp->d > d){return 0;}
    if((temp->d < d)&& (l->num_elements > 0)){
        while(((temp = temp->next) != NULL) && (temp->d < d)){
            count++;
        }
        if(temp == NULL){return l->num_elements;}
        if(temp->d >= d){return count+1;}
        //if(temp->d == d){return count+1;}
        //return count;   
    }
    else if((l->num_elements == 0)){
        //printf("Empty List");
        return 0;
    }
    return -1;
    
}

int find_value(LIST *l, unsigned int index, DATA *d) {
    NODE *temp;temp = l->head;
    if((index > 0) && (index < l->num_elements)){
        for(int i = 0; i<index; i++){
            temp = temp->next;
        }
        *d = temp->d;return index;
    }
    else if(index == 0){
        *d = temp->d;return 0;
    }
    else if(index > l->num_elements){
        printf("index out of range");
    }
    return -1;
}

void print_list(LIST *l) {
    NODE *temp;int count = 0;
    temp = l->head;
    if(temp == NULL){
        printf("\nEmpty List\n");
    }
    else{printf("%d %d\n",count,temp->d);
        while((temp = temp->next) != NULL){
            count++;
           printf("%d %d\n",count,temp->d); 
            }
    }
}

void free_list(LIST *l) {
    NODE *temp;temp = l->head;
    if (l->head == NULL) return;
    while(temp->next != NULL){
        free(temp->prev);
    }
}


int main(int ac, char *av[])
{
    int n, index, i;
    DATA d, d1;
    NODE *nptr;
    LIST l;

    if (ac < 2)
        ERR_MESG("Usage: linked-list <number>");
    n = atoi(av[1]);
    srand((int) time(NULL));

    init_list(&l);
    for (i = 0; i < n; i++) {
        d = rand() % MAX_VALUE;
        index = find_index_in_sorted(&l, d);
        if (-1 == insert(&l, index, d))
            fprintf(stderr, "Inserting %d at index %d failed\n", d, index);
        else
            fprintf(stderr, "Inserted %d at index %d successfully\n", d, index);
        print_list(&l);
    }

    while (l.num_elements > 0) {
        index = rand() % l.num_elements;
        if (-1 == find_value(&l, index, &d))
            fprintf(stderr, "Failed to find value at index %d\n", index);
        else {
            fprintf(stderr, "Found %d at index %d, deleting\n", d, index);
            if (-1 == delete(&l, index, &d1))
                fprintf(stderr, "Delete failed\n");
            else
                assert(d == d1);
            print_list(&l);
        }
    }

    free_list(&l);
    return 0;
}

/*int main(){
    LIST L;init_list(&L);
    printf("%d",find_index_in_sorted(&L,3));
    printf("%d",insert(&L,find_index_in_sorted(&L,3),3));
    //print_list(&L);
    







    return 0;
}*/
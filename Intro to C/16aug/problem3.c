#include<stdio.h>
#include<math.h>
int main(){
    int target;
    int i = 0;
    int dis_boxes;
    int nodes;
    int k;
    int nodes_sum;
    //int k;
    //int s[k];
    scanf("%d",&target);
    //printf("%d\n",target);
    getchar();
    scanf("%d",&dis_boxes);;
    getchar();
    scanf("%d",&k);
    //printf("%d\n",k);
    nodes = ceil((float)target/k);
    nodes_sum = nodes;
    //printf("%d\n",nodes);
    for(;i < dis_boxes - 1;i++){
        getchar();
        scanf("%d",&k);
        nodes = ceil((float)nodes/k);
        nodes_sum += nodes;
        
    }
    
    printf("%d\n",nodes_sum);








    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void hole_check(int i,int j,int **A, int *flag){
    if(A[i][j] == -1) *flag = *flag + 1;
}*/
// 5,6,7,8 labels for NE,NW,SE,SW directions respectively
void update_loc(int *i,int *j, int *direction, int **A,int m,int n,int *flag_hole,int *special_flag, int *count){//updates the location
    if(((*i == 0)||(*i == m-1))&&(*j != 0)&&(*j != n-1)){ //horizontal border blocks excluding corners
        if(*i == 0){
          switch (*direction){
            case 5: //NE
                *j = *j + 1;*direction = 7;
            break;
            case 6: //NW
                *j = *j - 1;*direction = 8;
            break;  
            case 7: //SE
                *i = *i + 1;*j = *j + 1;*direction = 7;
            break;
            case 8: //SW
                *i = *i + 1;*j = *j - 1;*direction = 8;
            break;
            }      
        }
        else{
            switch (*direction){
            case 5: //NE
                *i = *i - 1;*j = *j + 1;*direction = 5;
            break;
            case 6: //NW
                *i = *i - 1;*j = *j - 1;*direction = 6;
            break;    
            case 7: //SE
                *j = *j + 1;*direction = 5;
            break;
            case 8: //SW
                *j = *j - 1;*direction = 6;
            break;
        }
    }
    }
    else if(((*j == 0)||(*j == m-1))&&(*i != 0)&&(*i != n-1)){//vertical border blocks excluding corners
        if(*j == 0){
          switch (*direction){
            case 8: //SW
                *i = *i + 1;*direction = 7;
            case 6: //NW
                *i = *i - 1;*direction = 5;
            case 5: //NE
                *i = *i - 1;*j = *j + 1;*direction = 5;
            break;
            case 7: //SE
                *i = *i + 1;*j = *j + 1;*direction = 7;
            break;              
            }      
        }
        else{
            switch (*direction){
            case 7: //SE
                *i = *i - 1;*direction = 8;
            case 5: //NE
                *j = *j - 1;*direction = 6;
            case 6: //NW
                *i = *i - 1;*j = *j - 1;*direction = 6;
            break;
            case 8: //SW
                *i = *i + 1;*j = *j - 1;*direction = 8;
            break;
        }
    }
    }
    else if(((*i == 0)||(*i == m-1))&&((*j == 0)||(*j == n-1))){//4 corner blocks
        if((*i==0)&&(*j==0)){
                *i = *i + 1;*j = *j + 1;*direction = 7;
            }
            else if((*i==0)&&(*j=n-1)){
                *i = *i + 1;*j = *j - 1;*direction = 8;
            }
            else if((*i==m-1)&&(*j=n-1)){
                *i = *i - 1;*j = *j - 1;*direction = 6;
            }
            else{
                *i = *i - 1;*j = *j + 1;*direction = 5;
            }
    }
    else{ //central blocks except the border blocks
    switch (*direction){
    case 5: //NE
        *i = *i - 1;*j = *j + 1;
        break;
    case 6: //NW
        *i = *i - 1;*j = *j - 1;
        break;
    case 7: //SE
        *i = *i + 1;*j = *j + 1;
        break;
    case 8: //SW
        *i = *i + 1;*j = *j - 1;
        break;          
    }
    }
    *count = *count + 1;
    if(A[*i][*j] == -1){*flag_hole = *flag_hole + 1;}

}
int main(){
    int i,j,m,n,direction;
    int count = 0;
    int flag = 0;int special_flag = 0;
    scanf("%d",&m);scanf("%d",&n);
    int **A;int holes;scanf("%d",&holes);
    A = (int **)calloc(m,sizeof(int *));
    for(i=0;i<m;i++){
        *(A+i) = (int *)calloc(n,sizeof(int ));
    }
    for(i=0;i<holes;i++){
        int s,t;
        scanf("%d",&s);scanf("%d",&t);
        A[s][t] = -1; //-1 marks the position of hole in the array A
    }
    scanf("%d",&i);scanf("%d",&j);
    char *dir_string;
    dir_string = (char *)malloc(2*sizeof(char));
    scanf("%s",dir_string);

    if(strcmp("NE",dir_string) == 0){direction = 5;}//relabelling the directions to int
    else if(strcmp("NW",dir_string) == 0){direction = 6;}
    else if(strcmp("SE",dir_string) == 0){direction = 7;}
    else{direction = 8;}

    while((flag == 0)&&(count < m*n)){//non zero flag indicates that a hole is reached
                                      //count >= m*n will ensure that there is a cyclic path
       update_loc(&i,&j,&direction,A,m,n,&flag,&special_flag,&count);
       //printf("%d %d\n",i,j); //checking trajectory
    }
    //printf("%d\n",count);
    if(flag != 0){printf("Falls through hole at (%d,%d)\n",i,j);}
    else{printf("Bounces forever\n");}
    return 0;
}

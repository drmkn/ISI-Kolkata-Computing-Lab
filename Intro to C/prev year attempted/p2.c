#include <stdio.h>

int main(){
    int count = 0;
    int m,n;
    char d1,d2,d3,d4;
    int c1,c2,c3,c4;
    scanf("%d",&m);
    scanf("%d",&n);
    char A[m][n];
    int i,j;
    i=j=0;
    //printf("%d %d",m,n);
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){	
    	   scanf(" %c",&A[i][j]);
    	}
    }
    i = j = 0;
    while(count != m*n){
       while((j<n)&&(A[i][j] != 'x')&& (count != m*n)){ //Right
            if(A[i][j] == 'x'){
               if(j+1 == n || A[i][j+1] == 'x'){break;}
               else{j++;}
               //printf("1");
               }
            else{printf("%c ",A[i][j]);
            	count++;c1++;d1=A[i][j];	
            	A[i][j] = 'x';
            	if(j+1 == n || A[i][j+1] == 'x'){break;}
                else{j++;}
                //printf("2");
            	}
       }
       i++;
       while((i<m)&&(A[i][j] != 'x')&&(count != m*n)){ //Down
            if(A[i][j] == 'x'){
               if(i+1 == m || A[i+1][j] == 'x'){break;}
               else{i++;}
               //printf("3");
               }
            else{printf("%c ",A[i][j]);
            	count++;c2++;d2=A[i][j];
            	A[i][j] = 'x';
            	if(i+1 == m || A[i+1][j] == 'x'){break;}
                else{i++;}
            	//printf("4");
            	}
       }
       j--;
       while((j>-1)&&(A[i][j] != 'x')&&(count != m*n)){ //Left
            if(A[i][j] == 'x'){
               if(j-1 == -1 || A[i][j-1] == 'x'){break;}
               else{j--;}}
            else{printf("%c ",A[i][j]);
            	count++;c3++;d3= A[i][j];
            	A[i][j] = 'x';
            	if(j-1 == -1 || A[i][j-1] == 'x'){break;}
                else{j--;}
            	}
       }
       i--;
       while((i>-1)&&(A[i][j] != 'x')&&(count != m*n)){ //Up
            if(A[i][j] == 'x'){
               if(i-1 == -1 || A[i-1][j] == 'x'){break;}
               else{i--;}}
            else{printf("%c ",A[i][j]);
            	count++;c4++;d4=A[i][j];
            	A[i][j] = 'x';
            	if(i-1 == -1 || A[i-1][j] == 'x'){break;}
                else{i--;}
            	}
       }
       j++;
       //printf("%d %d %d %d\n",c1,c2,c3,c4);
       //printf("%d\n",count);
       //printf("%c %c %c %c\n",d1,d2,d3,d4);
   
    }


    return 0;
}

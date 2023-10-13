#include<stdio.h>
int main(){
    long long int sum = 0;
    int c;int flag = 0;int a;int count = 0;
    a = getchar();count++;
    sum += a - '0'; 
    while((c=getchar()) != '\n'){
        if((a-'0') == 0 && (c - '0') == 0){
            if(flag == 0){
                flag++;
            }
        }
        else{flag = 0;}
        sum =  sum + (c - '0');
        a = c;count++;
    }

    //if(ungetc(c,stdin) - '0' == 0) {flag++;}
    if((sum%3 == 0) && (sum%2 == 0) && (flag == 1)&&(count != 1)){
        printf("YES");
    }
    else if(count == 1){if(a-'0' == 0){printf("YES");}
                        else{printf("NO");}    }
    else{printf("NO");}

    return 0;
}
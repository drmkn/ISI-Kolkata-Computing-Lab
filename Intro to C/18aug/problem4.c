#include<stdio.h>
int main(){
    int rolls[1000];
    int emails[1000];
    int m = 5;
    int i = 0;
    int s;
    int comma_count = 0;
    for(;i < 5,i++){
       getchar();getchar();
       scanf("%d",&rolls);
       while(comma_count%3!=0 || comma_count == 0){
            s = getchar();
            if(s == ','){
              comma_count++;}
            else{continue;}   
       }
       while('\n' != (s = getchar())){
            scanf("")  
       
       }
       
    
    
    }


    return 0;

}

#include<stdio.h>
int main(){
    int input[100];
    int c;
    int count = 0;
    int i =0;
    int max_seq[1000];

    int max_count = 0;

    int dist_seq = 0;
    /*int seq[1000];
    int sizes[100];
    int count_O = 0;
    int count_s = 0;
    int len = 0;*/
    
    while((count < 100)&&('\n' != c )){
        scanf("%d",&input[count]);
        //s[count] = c;
        count++;
        c = getchar();
    }
    //for(;i<count;i++){printf("%d ",input[i]);}
    /*while(i<count){
         while(s[i] <= s[i+1]){
             ordered[count_O] = s[i];
             count_O++;
             i++;   
         }
         seq[count_O] = s[i];
         count_O++;
         seq[count_O] = ',';
         sizes[count_s] = count;*/
         
         
    for(;i<count;i++){
         if(input[i] <= input[i+1]){
             max_seq[i] = input[i];
             max_count++;
             //i++;}
             }
         else{max_seq[i] = input[i];
              max_count++;
              max_seq[i+1] = '\n';
              dist_seq++;
              i++;
              break;}
         }     
    while(i<count-1){
         int temp_seq[1000];
         int temp_count = 0;
         while(input[i] <= input[i+1]){
             temp_seq[temp_count] = input[i];
             temp_count++;
             i++;   
         }
         temp_seq[temp_count] = input[i];
         temp_count++;
         
         i++;
         if(max_count < temp_count){
            //int max_seq[1000];
            //int max_count = 0;
            int j = 0;
            for(;j<temp_count;j++){
                max_seq[j] = temp_seq[j];}
            max_seq[temp_count] = '\n';
            max_count = temp_count;
           
         }
         else if(max_count == temp_count){
                 int r = 0;
                 for(;r<temp_count;r++){
                     max_seq[(max_count*dist_seq)+dist_seq+r] = temp_seq[r];}
                     max_seq[(max_count*dist_seq)+dist_seq+r] = '\n';
                 dist_seq++;
                          
         }
         else{continue;}
      
         //printf("%d\n", temp_seq[0]);  
         //printf("%d\n", temp_seq[1]);   
    }   
    //printf("%d",max_count);      
    int l = 0;
    for(;l < (max_count*dist_seq)+dist_seq;l++)
        if(max_seq[l] == '\n'){
           printf("\n");}
        else{printf("%d ",max_seq[l]);}
    
    
    
    return 0;
    
    
    




}

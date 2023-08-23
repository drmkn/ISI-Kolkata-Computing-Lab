#include<stdio.h>
#include<ctype.h>
int main(){
    char letters[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','F','E','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int counts[26];
    int k;
    int i = 0;
    int j = 0;
    int r = 0;
    for(;r<26;r++){
       counts[r]=0;}
    while(EOF!= (k=getchar())){
         if(isalpha(k)){
            for(;i<26;i++){
                if((k == letters[i])||(k == letters[i+26])){
                  counts[i] += 1;
                  break;}
                else{ 1 == 1;}  
                
                }
             i = 0;   
         }
         else{continue;}
        // printf("%c\n",k);
         
    }
    //printf("%d",k);
    printf("\n");
    
    for(;j<26;j++){
       if(counts[j] > 0){
         printf("%c %d\n",letters[j],counts[j]);
       }
       else{continue;}
    
    }


    return 0;

}

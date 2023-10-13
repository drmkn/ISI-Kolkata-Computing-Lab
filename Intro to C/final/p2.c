#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include <math.h>

int main(int ac, char **av){
    FILE *fp;
    int m,n,i,j;int sum = 0;
    double d1,d2;int count = 0;
    fp = fopen(av[1],"r");
    if(NULL == fp){
       printf("Could not open file %s\n",av[1]); 
    }
    fscanf(fp,"%d",&m);fscanf(fp,"%d",&n);
    double A[m][n];double mean[n];double corr_coeff; double temp;
    int i_loc,j_loc;
    for(i=0;i<m;i++){
        for(j = 0;j<n;j++){
            fscanf(fp,"%lf",&A[i][j]);
            //printf("%f ",A[i][j]);
        }
    }
    for(i = 0;i<n;i++){
        for(j=0;j<m;j++){
            sum = sum + A[j][i];
        }
        mean[i] = (double)sum/m;
        //printf("%f ",mean[i]);
        sum = 0;
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            for(int k = 0;k<m;k++){
                corr_coeff += (A[k][i] - mean[i])*(A[k][j] - mean[j]);
                d1 += (A[k][i] - mean[i])*(A[k][i] - mean[i]);  
                d2 += (A[k][j] - mean[j])*(A[k][j] - mean[j]);
            }//printf("%lf %lf %lf\n",corr_coeff,d1,d2);
            corr_coeff = corr_coeff/(sqrt(d1*d2));
            //printf("%lf ",corr_coeff);
            
            if(count == 0){
                temp = corr_coeff;
                i_loc = i;j_loc = j;count++;
            }
            else{
                if(corr_coeff > temp){
                    temp = corr_coeff;
                    i_loc = i;j_loc = j;
                }

            }
        corr_coeff =0.0;d1 = 0.0;d2 = 0.0;
        }
    }
    printf("%d %d %.6lf",i_loc+1,j_loc+1,temp);


















    return 0;
}
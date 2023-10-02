#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double normal(void){
       double u_0,u_1,z_0,z_1,pi,z;
       //time_t t;
       //srand((unsigned) time(&t));
       pi = atan(1)*4;
       u_0 = (double)rand()/RAND_MAX;
       u_1 = (double)rand()/RAND_MAX;
       z_0 = sqrt(-2*log(u_0))*cos(2*pi*u_1);
       z_1 = sqrt(-2*log(u_1))*cos(2*pi*u_0);
       z = (z_0+z_1)/sqrt(2);
       return z;

}

int main(){
    /*double sum = 0;
    double sum2 = 0;
    double mean,x;
    double var;
    for(int i =0;i<N;i++){
        x = normal();
       sum += x;
       sum2 += x*x;
    }
    mean = sum/N;
    var = sum2/N - mean*mean;
    printf("%f %f",mean,var);*/
    int N =10000;
    double c1,c2,c3,d1,d2,d3,T;
    scanf("%lf",&c1);scanf("%lf",&d1);scanf("%lf",&c2);scanf("%lf",&d2);scanf("%lf",&c3);scanf("%lf",&d3);scanf("%lf",&T);
    int count = 0;
    double journey_time;
    for(int i = 0;i<N;i++){
       journey_time = d1*normal() + c1 + d2*normal() + c2 + d3*normal() + c3;
       if(journey_time >= T) count++;
    }
    printf("%lf\n",(double)count/N);

    return 0;

}

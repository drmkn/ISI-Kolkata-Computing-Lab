#include <stdio.h>
#include <math.h>
int main() {
    float a,b,c;
    printf("Input the values a,b and c in order:\n");
    scanf("%f %f %f", &a, &b, &c);
    int discriminant = b*b - 4*a*c ;
    
    if (discriminant >= 0){
        printf("Roots are %f and %f\n", (-b + sqrt(discriminant))/(2*a), (-b - sqrt(discriminant))/(2*a) );
        } else { printf("Roots are %f + %fi and %f - %fi\n", -b/2*a, sqrt(-1.0*discriminant)/2*a ,-b/2*a, sqrt(-1.0*discriminant)/2*a );}
       
    return 0;

}


#include<stdio.h>

float comp_area(float A[6]){
      float area;
      area = 0.5*((A[0]-A[4])*(A[3]-A[5])-(A[1]-A[5])*(A[2]-A[4]));
    
      if(area < 0){
         area = -1.0*area;}     

      return area;
}


int main(){
    float A[6];
    float area;
    char check;
    float new_area;
    printf("Enter the coordinate A\n");
    scanf("%f %f", &A[0], &A[1]);
    
    printf("Enter the coordinate B\n");
    scanf("%f %f", &A[2], &A[3]);
    
    printf("Enter the coordinate C\n");
    scanf("%f %f", &A[4], &A[5]);
    
    //area = 0.5*((A[0]-A[4])*(A[3]-A[5])-(A[1]-A[5])*(A[2]-A[4]));
    
    //if(area < 0){
       //area = -1.0*area;}
    area = comp_area(A);   
    
    printf("Area of traingle ABC is %f\n", area);
    
    printf("Want to continue for triangle DEF? Print Y if so\n");

    //float new_area;
    scanf("%s", &check);
    //printf("%c",check);
    if(check == 'Y'){
       printf("Enter the coordinate D\n");
       scanf("%f %f", &A[0], &A[1]);
    
       printf("Enter the coordinate E\n");
       scanf("%f %f", &A[2], &A[3]);
    
       printf("Enter the coordinate F\n");
       scanf("%f %f", &A[4], &A[5]);
       
       new_area = comp_area(A);
       //printf("%f", new_area);
       
       if(new_area == area ){
         printf("Triangles ABC and DEF are congruent\n");
       } else {printf("Triangles ABC and DEF are not congruent\n");}
       
       
       
       
       
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char *argv[]) {

    int n, k, *arr, arrayIndex;

    FILE *fp;

    /* OPENING THE INPUT FILE. VARIABLE `fp` POINTS TO THE OPENED FILE*/
    if (NULL == (fp = fopen (argv[1], "r"))) {
        printf ("Error opening file\n");
        exit (1);
    }
    
   

   /* Read the values of n and k */
    fscanf (fp, "%d", &n);
    fscanf (fp, "%d", &k);

    /* Create an array of size n and read in the elements */
    arr = (int *)(malloc (n * sizeof(int)));

    for (arrayIndex = 0; arrayIndex < n; arrayIndex++) {
        fscanf (fp, "%d", &arr[arrayIndex]);
    }

     /* WRITE YOUR CODE STARTING FROM HERE. 
       YOU MAY WRITE SEPARATE FUNCTIONS AS WELL */
    
    /* Do the computation as mentioned in question and print the pairs separated by space or `No such pair exists` in case of no match found */
    
    int i,j,p=0;
printf (" \n ");
for (i=0;i<n;i++)
{
for ( j=0;j<i;j++)
{
if (arr[i]+arr[j]==k)
{
if (j>j)
{
printf ("%d %d \n",arr[i] ,arr[j]);
}
else
printf ("%d %d \n",arr[j] ,arr[i]);
p=p+1;
}
 
}
}
if (p==0)
printf ("No such pair exists");

    /* YOUR CODE ENDS HERE */
    free (arr);
    fclose (fp);
    return 0;
}

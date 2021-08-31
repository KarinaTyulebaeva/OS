#include <stdio.h>
#include <limits.h>
#include<float.h>

int main(void)
{
    int a=INT_MAX;
    float b=FLT_MAX;
    double c=DBL_MAX;
    
    printf("INT_MAX = %d\n", a);
    printf("FLT_MAX = %f\n", b);
    printf("DBL_MAX = %f\n", c);
    
    printf("Size of int a: %ld \n",sizeof(a));
   printf("Size of float b: %ld \n",sizeof(b));
   printf("Size of double c: %ld \n",sizeof(c));
    return 0;
}

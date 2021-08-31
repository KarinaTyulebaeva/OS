#include <stdio.h>

int main(void)
{
    void swap(int*num1, int*num2){
       int temp = *num1;
       *num1 = *num2;
       *num2 = temp;
    }
    
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    swap(&a, &b);
    printf("%d \n", a);
    printf("%d \n", b);
      
    return 0;
}

#include <stdio.h>

int main(void)
{
    int n;
    int num=1;
    scanf("%d", &n);
  
    for(int i=0; i<n; i++){
        int count=n-i-1;
      
        while(count>0){
            printf(" ");
            count--;
        }
      
        for(int k=0; k<num; k++){
            printf("*");
        }
      
        printf(" \n");
        num+=2;
    }
    return 0;
}

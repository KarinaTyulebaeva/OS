#include <stdio.h>

int main()
{
    void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

  int arr[10]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  bubble_sort(arr, sizeof(arr)/sizeof(int));
  for(int i=0; i<sizeof(arr)/sizeof(int); i++)
  printf("%d ", arr[i]);
  return 0;

}

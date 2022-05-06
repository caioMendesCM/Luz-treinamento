#include <math.h>
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int arr[] = { 5, 2, 4, 1, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    selectionSort(arr, n);
    printf("[");
    for (i = 0; i < n; i++) {
      if(i == n - 1) {
          printf("%d", arr[i]);
      } else {
        printf("%d, ", arr[i]);
      }
    }
    printf("]");
    return 0;
}

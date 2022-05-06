#include <stdio.h>
#include <stdbool.h>
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// bubbleSort com escape caso o array já esteja ordenado.
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
}

int main()
{
    int *heapArr = (int *)malloc(5 * sizeof(int)); 
    int arr[] = {5, 1, 3, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    bubbleSort(arr, n);
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

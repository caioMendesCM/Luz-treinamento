#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = { 5, 2, 4, 1, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    insertionSort(arr, n);
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

//AIM: To implement Merge sort on a sufficient large set or large data set and measure it’s execution time to analysis it’s performance.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
     for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
  i = 0;
   j = 0;
   k = left;
 while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }while (i < n1)
        arr[k++] = leftArr[i++];
while (j < n2)
        arr[k++] = rightArr[j++];}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
       mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
merge(arr, left, mid, right);
    }
}
int main() {
    int n;
   printf("Enter number of elements: ");
    scanf("%d", &n);
   int arr[n];
   printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
      clock_t start, end;
    double cpu_time_used;
     start = clock();               // start time
    mergeSort(arr, 0, n - 1);
    end = clock();                 // end time
 cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
 printf("\n\nTime taken: %f seconds\n", cpu_time_used);
  return 0;
}

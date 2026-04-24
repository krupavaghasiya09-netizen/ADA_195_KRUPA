//AIM: To implement Bubble sort on a sufficient large set or large data set and measure it’s execution time to analysis it’s performance.

#include <stdio.h>
#include <time.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;
   for (i = 0; i < n ; i++) {
      for (j = 0 ; j < n -1-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
            }
 }
}
}
int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;
     printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n]
     printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    start = clock();              
    bubbleSort(arr, n);
    end = clock();                
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nExecution time: %f seconds\n", cpu_time_used);
    return 0;
}

//AIM:To develop and execute Quick Sort for large input values and evaluate the algorithm’s execution time.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
       quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int n;
    printf("Enter number of  elements for Quick sort: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();          // start time
    quickSort(arr, 0, n - 1); // Quick Sort call
    end = clock();            // end time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}

//AIM: Perform following sorting operation and measure the execution time for sufficient large input: Selection Sort

#include <stdio.h>
#include <time.h>
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
   for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
}
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    start = clock();              
    selectionSort(arr, n);
    end = clock();                
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nExecution time: %f seconds\n", cpu_time_used);
    return 0;
}

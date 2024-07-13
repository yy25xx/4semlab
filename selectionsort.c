#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    printf("Before Sort: ");
    printArray(arr, n);

    clock_t start = clock();
    qsort(arr, n, sizeof(int), compare);
    clock_t end = clock();

    printf("After Sort: ");
    printArray(arr, n);

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", timeTaken);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("****Merge Sort*****\nEnter the size of an array: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++) arr[i] = rand() % n;

    printf("Before Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    clock_t start = clock();
    qsort(arr, n, sizeof(int), compare);
    clock_t end = clock();

    printf("After Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

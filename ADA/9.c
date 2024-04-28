#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
int n;
printf("Enter the size of an array: ");
scanf("%d", &n);

int arr[n];
srand(time(NULL));
for (int i = 0; i < n; i++) {
arr[i] = rand() % n;
}

clock_t start = clock();
printf("Before Sort: ");
printArray(arr, n);
selectionSort(arr, n);
printf("After Sort: ");
printArray(arr, n);
clock_t end = clock();

double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken: %f seconds\n", timeTaken);

return 0;
}

void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}

int temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}
}

void printArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int p, int q);
int partition(int a[], int m, int p);
void interchange(int a[], int i, int j);

int main() {
int a[100000];
printf("*********QUICK SORT PROGRAM *********\n");
printf("Enter the number of elements to be sorted: ");
int n;
scanf("%d", &n);
srand(time(NULL));
printf("Array elements to be sorted are: \n");
for (int i = 0; i < n; i++) {
a[i] = rand() % 100;
printf("%d ", a[i]);
}
printf("\n");
a[n] = 999;
clock_t start, end;
start = clock();
quicksort(a, 0, n - 1);
end = clock();
printf("The sorted elements are: \n");
for (int i = 0; i < n; i++) {
printf("%d ", a[i]);

}
printf("\nThe time taken to sort is %ld ticks\n", (end - start));
printf("******** ******************* *******\n");

return 0;
}

void quicksort(int a[], int p, int q) {
int j;
if (p < q) {
j = partition(a, p, q);
quicksort(a, p, j - 1);
quicksort(a, j + 1, q);
}
}

int partition(int a[], int m, int p) {
int v, i = 0, j;
v = a[m];
i = m;
j = p;
while (i <= j) {
while (a[i] <= v)
i++;
while (a[j] > v)
j--;
if (i < j)
interchange(a, i, j);
}

interchange(a, m, j);
return j;
}

void interchange(int a[], int i, int j) {
int p;
p = a[i];
a[i] = a[j];
a[j] = p;
}
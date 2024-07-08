#include <stdio.h>

void sortArray(int n, float ratio[], float w[], float p[]);
void displayInfo(int n, float w[], float p[], float ratio[]);
void knapsack(int u, int n, float w[], float p[]);

int main() {
float w[10], p[10];
float ratio[10];
int n, m, i;

printf("********* KNAPSACK PROBLEM *******\n");
printf("Enter the total number of items: ");
scanf("%d", &n);

printf("Enter the weight of each item: \n");
for(i = 0; i < n; i++)
scanf("%f", &w[i]);

printf("Enter the profit of each item: \n");
for(i = 0; i < n; i++)
scanf("%f", &p[i]);

printf("Enter the knapsack capacity: ");
scanf("%d", &m);

for(i = 0; i < n; i++)
ratio[i] = p[i] / w[i];

printf("Information about knapsack problem are:\n");
displayInfo(n, w, p, ratio);
printf("Capacity = %d\n", m);

sortArray(n, ratio, w, p);
printf("\nDetails after sorting items based on Profit/Weight ratio in descending order:\n");
displayInfo(n, w, p, ratio);

knapsack(m, n, w, p);
printf("*************************************\n");

return 0;
}

void sortArray(int n, float ratio[], float w[], float p[]) {
int i, j;
for(i = 0; i < n; i++)
for(j = 0; j < n - i - 1; j++) {
if(ratio[j] < ratio[j + 1]) {

float temp = ratio[j];
ratio[j] = ratio[j + 1];
ratio[j + 1] = temp;

temp = w[j];
w[j] = w[j + 1];
w[j + 1] = temp;

temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}

void displayInfo(int n, float w[], float p[], float ratio[]) {
int i;
printf("ITEM\tWEIGHT\tPROFIT\tRATIO(PROFIT/WEIGHT)\n");
for(i = 0; i < n; i++)
printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, w[i], p[i], ratio[i]);
}

void knapsack(int u, int n, float w[], float p[]) {
float x[10], tp = 0;
int i;

for(i = 0; i < n; i++)
x[i] = 0;

for(i = 0; i < n; i++) {
if(w[i] > u)
break;
else {
x[i] = 1;
tp += p[i];
u -= w[i];
}
}

if(i < n) {
x[i] = (float)u / w[i];
tp += x[i] * p[i];
}

printf("\nThe result is = ");
for(i = 0; i < n; i++)
printf("\t%.2f", x[i]);
printf("\nMaximum profit is = %.2f\n", tp);
}

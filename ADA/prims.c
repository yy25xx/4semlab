#include <stdio.h>
int prims(int cost[][10], int n, int mincost) {
int nearV[10] = {0}, t[10][3] = {0}, u = 0, i, j, k;
for (i = 2; i <= n; i++)
nearV[i] = 1;
nearV[1] = 0;
for (i = 1; i < n; i++) {
int min = 999;
for (j = 1; j <= n; j++) {
if (nearV[j] != 0 && cost[j][nearV[j]] < min) {
min = cost[j][nearV[j]];
u = j;
}
}
t[i][1] = u;
t[i][2] = nearV[u];
mincost += min;
nearV[u] = 0;
for (k = 1; k <= n; k++) {
if (nearV[k] != 0 && cost[k][nearV[k]] > cost[k][u])
nearV[k] = u;
}
printf("%d) Minimum edge is (%d,%d) and its cost is: %d\n", i, t[i][1], t[i][2], min);
}
return mincost;
}

int main() {
int cost[10][10], i, j, mincost = 0;
printf("********* PRIM'S ALGORITHM *********\n");
printf("Enter the number of nodes: ");
int n;
scanf("%d", &n);
printf("Enter the cost matrix:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
scanf("%d", &cost[i][j]);
}
}
printf("The entered cost matrix is:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
printf("%d\t", cost[i][j]);
}
printf("\n");
}
printf("Minimum Spanning Tree Edges and costs are:\n");
mincost = prims(cost, n, mincost);
printf("The minimum spanning tree cost is: %d\n", mincost);
printf("***********************************\n");
return 0;
}
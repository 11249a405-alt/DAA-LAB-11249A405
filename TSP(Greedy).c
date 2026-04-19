#include <stdio.h>

int main() {
    int n, i, j, visited[10]={0};
    int cost[10][10], min, next, total = 0;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    int current = 0;
    visited[current] = 1;

    printf("Path: %d ", current);

    for(i=0;i<n-1;i++) {
        min = 999;
        for(j=0;j<n;j++) {
            if(!visited[j] && cost[current][j] < min) {
                min = cost[current][j];
                next = j;
            }
        }
        printf("-> %d ", next);
        visited[next] = 1;
        total += min;
        current = next;
    }

    total += cost[current][0];
    printf("-> 0\nTotal cost = %d\n", total);

    return 0;
}
/*
Output:
Enter number of cities: 4
Enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Path: 0 -> 1 -> 3 -> 2 -> 0
Total cost = 80
*/

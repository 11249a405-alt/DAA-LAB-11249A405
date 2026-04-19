#include <stdio.h>

int main() {
    int n, i, j, min, u, v, total = 0;
    int cost[10][10], visited[10]={0};

    printf("Enter vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    visited[0]=1;

    for(int k=0;k<n-1;k++) {
        min=999;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(visited[i] && !visited[j] && cost[i][j]<min) {
                    min=cost[i][j];
                    u=i; v=j;
                }
            }
        }
        printf("%d -> %d = %d\n", u, v, min);
        total += min;
        visited[v]=1;
    }

    printf("Total cost = %d\n", total);

    return 0;
}
/*
Output:
Enter vertices: 4
Enter cost matrix:
0 2 3 3
2 0 4 2
3 4 0 5
3 2 5 0
0 -> 1 = 2
1 -> 3 = 2
0 -> 2 = 3
Total cost = 7
*/

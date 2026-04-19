#include <stdio.h>

int main() {
    int n, i, j, min, u;
    int cost[10][10], dist[10], visited[10]={0};

    printf("Enter vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    for(i=0;i<n;i++)
        dist[i]=999;

    dist[0]=0;

    for(i=0;i<n;i++) {
        min=999;
        for(j=0;j<n;j++) {
            if(!visited[j] && dist[j]<min) {
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        for(j=0;j<n;j++) {
            if(!visited[j] && cost[u][j] && dist[u]+cost[u][j]<dist[j]) {
                dist[j]=dist[u]+cost[u][j];
            }
        }
    }

    printf("Distances:\n");
    for(i=0;i<n;i++)
        printf("0 -> %d = %d\n", i, dist[i]);

    return 0;
}
/*
Output:
Enter vertices: 4
Enter cost matrix:
0 1 4 0
1 0 2 6
4 2 0 3
0 6 3 0
Distances:
0 -> 0 = 0
0 -> 1 = 1
0 -> 2 = 3
0 -> 3 = 6
*/

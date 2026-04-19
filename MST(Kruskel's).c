#include <stdio.h>

int parent[10];

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

void uni(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, cost[10][10], min, i, j, a, b, u, v, total=0;

    printf("Enter vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    for(int k=0;k<n-1;k++) {
        min=999;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(cost[i][j]<min) {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find(u);
        v=find(v);

        if(u!=v) {
            printf("%d -> %d = %d\n", a, b, min);
            total += min;
            uni(u,v);
        }
        cost[a][b]=cost[b][a]=999;
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

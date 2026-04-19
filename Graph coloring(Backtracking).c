#include <stdio.h>

int graph[10][10], color[10], n, m;

int safe(int v, int c) {
    for(int i=0;i<n;i++) {
        if(graph[v][i] && color[i]==c)
            return 0;
    }
    return 1;
}

void solve(int v) {
    if(v==n) {
        for(int i=0;i<n;i++)
            printf("%d ", color[i]);
        printf("\n");
        return;
    }

    for(int c=1;c<=m;c++) {
        if(safe(v,c)) {
            color[v]=c;
            solve(v+1);
            color[v]=0;
        }
    }
}

int main() {
    printf("Enter vertices: ");
    scanf("%d",&n);

    printf("Enter colors: ");
    scanf("%d",&m);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    solve(0);

    return 0;
}
/*
Output:
Enter vertices: 4
Enter colors: 3
Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
1 2 3 2
2 1 2 1
*/

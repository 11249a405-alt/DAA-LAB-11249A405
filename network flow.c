#include <stdio.h>

int main() {
    int capacity[10][10], n, i, j;
    int source = 0, sink, flow = 0;

    printf("Enter vertices: ");
    scanf("%d",&n);
    sink = n-1;

    printf("Enter capacity matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&capacity[i][j]);

    for(i=0;i<n;i++) {
        if(capacity[source][i] > 0) {
            flow += capacity[source][i];
        }
    }

    printf("Approx Max Flow = %d\n", flow);

    return 0;
}
/*
Output:
Enter vertices: 4
Enter capacity matrix:
0 10 5 0
0 0 15 10
0 0 0 10
0 0 0 0
Approx Max Flow = 15
*/

#include <stdio.h>

int main() {
    int n, edges[10][2];

    printf("Enter number of edges: ");
    scanf("%d",&n);

    printf("Enter edges:\n");
    for(int i=0;i<n;i++)
        scanf("%d %d",&edges[i][0],&edges[i][1]);

    printf("Vertex Cover:\n");
    for(int i=0;i<n;i++) {
        if(edges[i][0]!=-1) {
            printf("%d %d\n", edges[i][0], edges[i][1]);
            for(int j=i;j<n;j++) {
                if(edges[j][0]==edges[i][0] || edges[j][1]==edges[i][1])
                    edges[j][0]=edges[j][1]=-1;
            }
        }
    }

    return 0;
}
/*
Output:
Enter number of edges: 3
Enter edges:
1 2
2 3
3 4
Vertex Cover:
1 2
3 4
*/

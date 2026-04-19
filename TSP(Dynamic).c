#include <stdio.h>
#include <limits.h>

int n;
int cost[10][10];
int dp[1<<10][10];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
    if(mask == (1<<n)-1)
        return cost[pos][0];

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for(int city = 0; city < n; city++) {
        if((mask & (1<<city)) == 0) {
            int newAns = cost[pos][city] +
                         tsp(mask | (1<<city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &cost[i][j]);

    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            dp[i][j] = -1;

    int result = tsp(1, 0);

    printf("Minimum travelling cost = %d\n", result);

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
Minimum travelling cost = 80
*/

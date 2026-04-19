#include <stdio.h>

int board[10], n;

int safe(int row, int col) {
    for(int i=0;i<col;i++) {
        if(board[i]==row || abs(board[i]-row)==abs(i-col))
            return 0;
    }
    return 1;
}

void solve(int col) {
    if(col==n) {
        for(int i=0;i<n;i++)
            printf("%d ", board[i]);
        printf("\n");
        return;
    }

    for(int i=0;i<n;i++) {
        if(safe(i,col)) {
            board[col]=i;
            solve(col+1);
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d",&n);

    solve(0);

    return 0;
}
/*
Output:
Enter number of queens: 4
1 3 0 2
2 0 3 1
*/

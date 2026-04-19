#include <stdio.h>

int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Series:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }

    return 0;
}
/*
Output:
Enter number of terms: 5
Series:
0 1 1 2 3
*/

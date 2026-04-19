#include <stdio.h>

int main() {
    int n, i, fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        fact = fact * i;
        printf("Step %d: %d\n", i, fact);
    }

    printf("Factorial = %d\n", fact);

    return 0;
}
/*
Output:
Enter a number: 5
Step 1: 1
Step 2: 2
Step 3: 6
Step 4: 24
Step 5: 120
Factorial = 120
*/

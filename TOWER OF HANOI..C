#include <stdio.h>

void TOH(int n, char source, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c -> %c\n", source, dest);
        return;
    }
    TOH(n-1, source, dest, aux);
    printf("Move disk %d from %c -> %c\n", n, source, dest);
    TOH(n-1, aux, source, dest);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nSteps:\n");
    TOH(n, 'A', 'B', 'C');

    return 0;
}
/*
Output:
Enter number of disks: 3

Steps:
Move disk 1 from A -> C
Move disk 2 from A -> B
Move disk 1 from C -> B
Move disk 3 from A -> C
Move disk 1 from B -> A
Move disk 2 from B -> C
Move disk 1 from A -> C
*/

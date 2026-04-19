#include <stdio.h>

int main() {
    int n, c, i, bins = 1;
    int weight[20], rem;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &c);

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    rem = c;

    for(i = 0; i < n; i++) {
        if(weight[i] <= rem) {
            rem -= weight[i];
            printf("Item %d -> Same bin\n", weight[i]);
        } else {
            bins++;
            rem = c - weight[i];
            printf("Item %d -> New bin\n", weight[i]);
        }
    }

    printf("Total bins = %d\n", bins);

    return 0;
}
/*
Output:
Enter number of items: 5
Enter bin capacity: 10
Enter weights:
2 5 4 7 1
Item 2 -> Same bin
Item 5 -> Same bin
Item 4 -> New bin
Item 7 -> New bin
Item 1 -> Same bin
Total bins = 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;

    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];

    srand(time(0));

    for(i=0;i<n;i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    int r = rand() % n;

    printf("\nRandom element: %d\n", arr[r]);

    return 0;
}
/*
Output:
Enter size: 5
23 45 12 67 89
Random element: 12
*/

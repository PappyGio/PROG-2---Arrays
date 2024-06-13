// same as split the array file but with malloc/ calloc
//dynamic memory allocation 


#include <stdio.h>
#include <stdlib.h>

void printRes(int arr[], int even, int odd, int num);

void printRes(int arr[], int even, int odd, int num) {
    int i;
    int *a1 = (int *)malloc(odd * sizeof(int));
    int *a2 = (int *)malloc(even * sizeof(int));

    int ctr1 = 0, ctr2 = 0;
    for (i = 0; i < 8; i++) {
        if (arr[i] % 2 != 0) {
            a1[ctr1++] = arr[i];
        } else {
            a2[ctr2++] = arr[i];
        }
    }

    if (num == 0) {
        for (i = 0; i < 8; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nsum = %d\n", arr[8]);
    } else if (num == 1) {
        for (i = 0; i < odd; i++) {
            printf("%d ", a1[i]);
        }
        printf("\n");
    } else if (num == 2) {
        for (i = 0; i < even; i++) {
            printf("%d ", a2[i]);
        }
        printf("\n");
    } else {
        printf("INVALID MY FRIEND\n");
    }

    if (odd == even) {
        printf("\nBoth arrays have the same size:\n");
        for (i = 0; i < odd; i++) {
            printf("%d ", a1[i] + a2[i]);
        }
        printf("\n");
    } else {
        printf("0\n");
    }

    free(a1);
    free(a2);
}

int main() {
    int i, a[9], odd = 0, even = 0, disp;

    a[8] = 0;

    printf("Input 8 integers: ");

    for (i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        a[8] += a[i];
    }

    printf("----------Welcome my friend----------\n");
    printf("----------CHOOSE HERE!----------\n");
    printf("ODD[1], EVEN[2], BOTH[0]:  ");
    scanf("%d", &disp);

    printf("\n");

    printRes(a, even, odd, disp);

    return 0;
}

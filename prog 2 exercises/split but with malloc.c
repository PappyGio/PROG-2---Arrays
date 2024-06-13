// same as split the array file but with malloc/ calloc
//dynamic memory allocation 

#include <stdio.h>
#include <stdlib.h>

// Function to print the results based on user input
void printRes(int arr[], int even, int odd, int num) {
    int i;
    
    // Dynamically allocate memory for arrays to store odd and even numbers
    int *a1 = (int *)malloc(odd * sizeof(int));
    int *a2 = (int *)malloc(even * sizeof(int));

    // Check if memory allocation was successful
    if (a1 == NULL || a2 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int ctr1 = 0, ctr2 = 0;
    // Split the array into odd and even numbers
    for (i = 0; i < 8; i++) {
        if (arr[i] % 2 != 0) {
            a1[ctr1++] = arr[i];
        } else {
            a2[ctr2++] = arr[i];
        }
    }

    // Display the original array and its sum
    if (num == 0) {
        for (i = 0; i < 8; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nsum = %d\n", arr[8]);
    } 
    // Display the array of odd numbers
    else if (num == 1) {
        for (i = 0; i < odd; i++) {
            printf("%d ", a1[i]);
        }
        printf("\n");
    } 
    // Display the array of even numbers
    else if (num == 2) {
        for (i = 0; i < even; i++) {
            printf("%d ", a2[i]);
        }
        printf("\n");
    } 
    // Handle invalid input
    else {
        printf("INVALID MY FRIEND\n");
    }

    // If both arrays have the same size, display the sum of corresponding elements
    if (odd == even) {
        printf("\nBoth arrays have the same size:\n");
        for (i = 0; i < odd; i++) {
            printf("%d ", a1[i] + a2[i]);
        }
        printf("\n");
    } 
    // If the sizes are different, print 0
    else {
        printf("0\n");
    }

    // Free the dynamically allocated memory
    free(a1);
    free(a2);
}

int main() {
    int i, a[9], odd = 0, even = 0, disp;

    a[8] = 0; // Initialize the sum to 0

    printf("Input 8 integers: ");

    // Input 8 integers and calculate the number of odd and even numbers
    for (i = 0; i < 8; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        a[8] += a[i]; // Add each number to the sum
    }

    printf("----------Welcome my friend----------\n");
    printf("----------CHOOSE HERE!----------\n");
    printf("ODD[1], EVEN[2], BOTH[0]:  ");
    scanf("%d", &disp); // Get user choice

    printf("\n");

    // Call the function to print the results based on user choice
    printRes(a, even, odd, disp);

    return 0;
}

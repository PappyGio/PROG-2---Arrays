


#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[10];
    int *newArray = NULL;
    int i, firstThreeIndex = -1;
    int newArraySize = 0;

    // Step 1: Input 10 integers between 0 and 5
    printf("Enter 10 integers between 0 and 5:\n");
    for (i = 0; i < 10; i++) {
        do {
            printf("Enter integer %d: ", i + 1);
            scanf("%d", &array[i]);
            if (array[i] < 0 || array[i] > 5) {
                printf("Please enter a number between 0 and 5.\n");
            }
        } while (array[i] < 0 || array[i] > 5);
    }

    // Step 2: Sort the array using bubble sort
    bubbleSort(array, 10);

    // Step 3: Find the first occurrence of 3
    for (i = 0; i < 10; i++) {
        if (array[i] == 3) {
            firstThreeIndex = i;
            break;
        }
    }

    // Step 4: Create the new array dynamically
    if (firstThreeIndex != -1) {
        // Calculate the size of the new array
        for (i = firstThreeIndex; i < 10; i++) {
            if (array[i] <= 3) {
                newArraySize++;
            }
        }

        // Allocate memory for the new array
        newArray = (int *)malloc(newArraySize * sizeof(int));
        if (newArray == NULL) {
            printf("Memory allocation failed!\n");
            return 1; // Exit if memory allocation fails
        }

        // Fill the new array with values that are 3 or below
        int j = 0;
        for (i = firstThreeIndex; i < 10; i++) {
            if (array[i] <= 3) {
                newArray[j++] = array[i];
            }
        }
    }

    // Step 5: Output the arrays
    printf("Sorted original array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("New array: ");
    if (newArray != NULL) {
        for (i = 0; i < newArraySize; i++) {
            printf("%d ", newArray[i]);
        }
        printf("\n");
    } else {
        printf("No values to display in the new array.\n");
    }

    // Free the dynamically allocated memory
    free(newArray);

    return 0;
}

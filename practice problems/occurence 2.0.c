/*Make an array that accepts 10 integer inputs of 0 to 5 

in the first occurrence of 3, make a new array that only 
has the values of 3 and below 

Example output

2 3 2 1 2 3 3 4 1 5
3 2 1 2 3 3 1

*/
#include <stdio.h>
#include <stdlib.h>

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
        
        // Step 2: Find the first occurrence of 3
        if (firstThreeIndex == -1 && array[i] == 3) {
            firstThreeIndex = i;
        }
    }

    // Step 3: Create the new array dynamically
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

    // Step 4: Output the arrays
    printf("Original array: ");
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


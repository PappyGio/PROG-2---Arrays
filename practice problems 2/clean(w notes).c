#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* arrayCleaning(int arr[], int count, int* cleanedSize);
void display(int *arr, int cleanedCount);

int main() {
    int arr[100];
    int arrCount = 0;
    int *cleanedArr;
    int i;

    printf("Input how many items in the array: ");
    scanf("%d", &arrCount);

    printf("Input Array Values: ");
    for (i = 0; i < arrCount; i++) {
        scanf("%d", &arr[i]);
    }

    int cleanedSize = 0;
    cleanedArr = arrayCleaning(arr, arrCount, &cleanedSize);

    if (cleanedSize == 0) {
        printf("Oh no! Data is fully corrupted and cannot be recovered!\n");
    } else {
        printf("Data has been recovered!\n");
        display(cleanedArr, cleanedSize);
        free(cleanedArr);
    }

    return 0;
}

int* arrayCleaning(int arr[], int count, int* cleanedSize) {
    int i, inCorruptedSegment = 0;
    int *cleaned = (int*)malloc(sizeof(int) * count);
    if (cleaned == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    *cleanedSize = 0;

    for (i = 0; i < count; i++) {
        if (arr[i] == -1) {
            inCorruptedSegment = !inCorruptedSegment; // Toggle the flag
        } else if (!inCorruptedSegment) {
            cleaned[*cleanedSize] = arr[i];
            (*cleanedSize)++;
        }
    }

    // Resize the array to the exact size of cleaned data
    cleaned = (int*)realloc(cleaned, sizeof(int) * (*cleanedSize));
    if (cleaned == NULL && *cleanedSize > 0) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    return cleaned;
}

void display(int *arr, int cleanedCount) {
    int i;
    printf("Cleaned Data: ");
    for (i = 0; i < cleanedCount; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


/* 

ADDDITIONAAL NOTES 

WITH THE HELP FROM CHAT GPT:)

MAIN FUNCTION:

Variable Declarations: Declares variables to store the array and its count.

Input Section: Prompts the user for the number of items and the values in the array.

Array Cleaning: Calls arrayCleaning to clean the array and determine the size of the cleaned array.

Output Section: Checks if any data was recovered. If yes, displays the cleaned array; otherwise, prints an error message.

Memory Deallocation: Frees the allocated memory for the cleaned array.






arrayCleaning Function:

Variable Declarations: Declares variables to iterate through the array and manage the corrupted segment flag.

Memory Allocation: Allocates memory for the cleaned array and checks for allocation failure.

Cleaning Logic: Iterates through the array, toggling the flag to skip corrupted segments and collecting non-corrupted data.

Memory Reallocation: Resizes the cleaned array to fit the exact size of the cleaned data and checks for reallocation errors.

Return Statement: Returns the cleaned array.


display Function:

Output Formatting: Displays the cleaned data with a simple for  loop and formatted output.



CREDITS TO CHAT GPT for helping me:)
*/

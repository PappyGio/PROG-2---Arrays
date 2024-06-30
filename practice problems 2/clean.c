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

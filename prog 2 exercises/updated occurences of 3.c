/*Make an array that accepts 10 integer inputs of 0 to 5 

in the first occurence of 3, make a new array that only 
has the values of 3 and below 

Example output

2 3 2 1 2 3 3 4 1 5
3 2 1 2 3 3 1
3 1   ----------->>>>> unique
3 1 1 3 ------->>>>>>> palindrome
1 1 3 3 ------->>>>>> sort

new test case 

1 2 1 2 5 4 4 5 1 3
This should have only 1 integer output for all functions.

==========NEW UPDATE=======

STILL gonna update/optimize it later

*/







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int* arr) {
    for(int i = 1; i <= arr[0]; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void firstOccurence(int* arr1, int* newArr) {
    int count = 1, temp = 0;

    newArr[0] = arr1[0];

    for(int i = 1; i <= arr1[0]; i++) {
        if (arr1[i] == 3) {
            temp = i;
            break;
        }
    }
    for(int i = temp; i <= arr1[0]; i++) {
        if (arr1[i] <= 3) {
            newArr[count++] = arr1[i];
        }
    }
    newArr[0] = count - 1;
    newArr = (int *)realloc(newArr, count * sizeof(int));
    display(newArr);
}

void findUnique(int* arr2) {
    int count = 1;
    int* arr = (int*)malloc(sizeof(int) * arr2[0]);
    arr[0] = arr2[0];

    for (int i = 1; i <= arr2[0]; i++) {
        int isUnique = 1;
        for (int j = 1; j < i; j++) {
            if (arr2[i] == arr2[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            arr[count++] = arr2[i];
        }
    }
    arr2[0] = count - 1;
    arr2 = (int*)realloc(arr2, count * sizeof(int));
    for (int i = 1; i <= arr2[0]; i++) {
        arr2[i] = arr[i];
    }
    display(arr2);
    free(arr);
}

void palindrome(int* arr) {

 if (arr[0] == 1) {
        display(arr);
        return;
    }
    
    int size = arr[0] * 2;
    int* newArr = (int*)malloc(size * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int j = 1;
    for (int i = 1; i <= arr[0]; i++) {
        newArr[j++] = arr[i];
    }
    for (int i = arr[0]; i > 0; i--) {
        newArr[j++] = arr[i];
    }

    arr[0] = size;
    arr = (int*)realloc(arr, (size + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        free(newArr);
        return;
    }

    for (int i = 1; i <= size; i++) {
        arr[i] = newArr[i];
    }

    display(arr);
    free(newArr);
}

void sort(int* arr) {
    int temp = 0;
    for (int i = 1; i <= arr[0]; i++) {
        for (int j = i + 1; j <= arr[0]; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    display(arr);
}

int main() {
    int arr1[11];
    arr1[0] = 10;
    int* arr2 = (int*)malloc(sizeof(int) * (arr1[0] + 1));

    for (int i = 1; i <= arr1[0]; i++) {
        printf("Enter your element %d for the array: ", i);
        scanf("%d", &arr1[i]);
    }

    printf("First Occurrences of 3 and after: ");
    firstOccurence(arr1, arr2);
    printf("Unique Numbers: ");
    findUnique(arr2);
    printf("The palindrome: ");
    palindrome(arr2);
    printf("Bubble sort: ");
    sort(arr2);

    free(arr2);
    return 0;
}

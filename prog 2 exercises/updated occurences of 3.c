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
    for(int i = 1; i <= arr[0]; i++) {  // Iterate from 1 to the size of the array (arr[0])
        printf("%d ", arr[i]);          // Print each element of the array followed by a space
    }
    printf("\n");                      // Move to the next line after printing all elements
}

void firstOccurence(int* arr1, int* newArr) {
    int count = 1, temp = 0;           // Initialize count and temp variables

    newArr[0] = arr1[0];               // Set the first element of newArr to the size of arr1

    for(int i = 1; i <= arr1[0]; i++) {  // Iterate through arr1
        if (arr1[i] == 3) {             // Find the first occurrence of the number 3
            temp = i;                   // Store its index in temp
            break;                      // Exit the loop once found
        }
    }
    for(int i = temp; i <= arr1[0]; i++) {  // Continue from temp to the end of arr1
        if (arr1[i] <= 3) {            // Copy elements less than or equal to 3 to newArr
            newArr[count++] = arr1[i]; // Increment count and assign the element to newArr
        }
    }
    newArr[0] = count - 1;             // Set newArr size to count minus one (excluding the first element)
    newArr = (int *)realloc(newArr, count * sizeof(int));  // Resize newArr based on count
    display(newArr);                   // Display the modified newArr
}

void findUnique(int* arr2) {
    int count = 1;                     // Initialize count to 1 (start from the first element)
    int* arr = (int*)malloc(sizeof(int) * arr2[0]);  // Allocate memory for arr based on arr2 size
    arr[0] = arr2[0];                  // Set the first element of arr to the size of arr2

    for (int i = 1; i <= arr2[0]; i++) {  // Iterate through arr2
        int isUnique = 1;              // Assume the current element is unique
        for (int j = 1; j < i; j++) {  // Compare current element with previous elements
            if (arr2[i] == arr2[j]) {  // If duplicate is found
                isUnique = 0;          // Mark as not unique
                break;                 // Exit the loop
            }
        }
        if (isUnique) {                // If the element is unique
            arr[count++] = arr2[i];    // Add it to arr and increment count
        }
    }
    arr2[0] = count - 1;              // Set arr2 size to count minus one (excluding the first element)
    arr2 = (int*)realloc(arr2, count * sizeof(int));  // Resize arr2 based on count
    for (int i = 1; i <= arr2[0]; i++) {  // Copy elements from arr to arr2
        arr2[i] = arr[i];             // Assign each element from arr to arr2
    }
    display(arr2);                    // Display the modified arr2
    free(arr);                        // Free the memory allocated for arr
}

void palindrome(int* arr) {
    if (arr[0] == 1) {                // If the size of arr is 1
        display(arr);                 // Display the array as it is (already a palindrome)
        return;                       // Exit the function
    }

    int size = arr[0] * 2;            // Calculate the size needed for the palindrome
    int* newArr = (int*)malloc(size * sizeof(int));  // Allocate memory for the new array
    if (newArr == NULL) {             // If memory allocation fails
        printf("Memory allocation failed\n");  // Print error message
        return;                       // Exit the function
    }

    int j = 1;                        // Initialize index variable for newArr
    for (int i = 1; i <= arr[0]; i++) {  // Copy elements of arr to newArr
        newArr[j++] = arr[i];         // Append elements in order
    }
    for (int i = arr[0]; i > 0; i--) {  // Copy elements of arr in reverse order to newArr
        newArr[j++] = arr[i];         // Append elements in reverse order
    }

    arr[0] = size;                    // Update arr size to the palindrome size
    arr = (int*)realloc(arr, (size + 1) * sizeof(int));  // Resize arr based on the palindrome size
    if (arr == NULL) {                // If memory reallocation fails
        printf("Memory reallocation failed\n");  // Print error message
        free(newArr);                 // Free memory allocated for newArr
        return;                       // Exit the function
    }

    for (int i = 1; i <= size; i++) {  // Copy elements from newArr to arr
        arr[i] = newArr[i];           // Assign each element from newArr to arr
    }

    display(arr);                     // Display the modified arr (palindrome)
    free(newArr);                     // Free memory allocated for newArr
}

void sort(int* arr) {
    int temp = 0;                     // Initialize temporary variable for swapping
    for (int i = 1; i <= arr[0]; i++) {  // Iterate through the array
        for (int j = i + 1; j <= arr[0]; j++) {  // Compare current element with the rest
            if (arr[i] > arr[j]) {    // If current element is greater than the next
                temp = arr[i];        // Swap elements
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    display(arr);                     // Display the sorted array
}

int main() {
    int arr1[11];                     // Declare array arr1 with size 11
    arr1[0] = 10;                     // Set the first element of arr1 to 10 (number of elements)

    for (int i = 1; i <= arr1[0]; i++) {  // Iterate through arr1 elements
        printf("Enter your element %d for the array: ", i);  
        scanf("%d", &arr1[i]);         // Read integer input and store in arr1
    }

    int* arr2 = (int*)malloc(sizeof(int) * (arr1[0] + 1));  // Allocate memory for arr2 based on arr1 size

    printf("First Occurrences of 3 and after: ");  // 
    firstOccurence(arr1, arr2);       // Call function to find first occurrences and display results
    printf("Unique Numbers: ");       // 
    findUnique(arr2);                 // Call function to find unique numbers and display results
    printf("The palindrome: ");       // 
    palindrome(arr2);                 // Call function to create palindrome and display results
    printf("Bubble sort: ");          //
    sort(arr2);                       // Call function to sort array and display results

    free(arr2);                       // Free memory allocated for arr2
    return 0;                         // 

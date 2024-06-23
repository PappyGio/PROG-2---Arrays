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

// Function to display the elements of an array
void display(int* arr) {
    for(int i = 1; i <= arr[0]; i++) {   // -------------> Loop through the array starting from index 1 to the size of the array
        printf("%d ", arr[i]);           
    }
    printf("\n");                        
}

// Function to find the first occurrence of the number 3 and elements after it
void firstOccurence(int* arr1, int* newArr) {
    int count = 1, temp = 0;             //-----------------> Initialize count for new array and temporary variable for index

    newArr[0] = arr1[0];                 //-----------------> Set the initial size of newArr to be the same as arr1

    // Loop to find the first occurrence of 3
    for(int i = 1; i <= arr1[0]; i++) {
        if (arr1[i] == 3) {              //----------------> Check if the current element is 3
            temp = i;                    //----------------> Store the index of the first occurrence of 3
            break;                       // ---------------> Exit the loop once 3 is found
        }
    }

    // Loop to copy elements from the first occurrence of 3 and after
    for(int i = temp; i <= arr1[0]; i++) {
        if (arr1[i] <= 3) {              //--------------> Check if the current element is less than or equal to 3
            newArr[count++] = arr1[i];   //--------------> Copy the element to newArr and increment the count
        }
    }
    newArr[0] = count - 1;               //--------------> Update the size of newArr
    newArr = (int *)realloc(newArr, count * sizeof(int)); //---------------> Reallocate memory for newArr based on the new size
    display(newArr);                     //------------------> Display the new array
}

// Function to find unique elements in an array
void findUnique(int* arr2) {
    int count = 1;                       //---------------> Initialize count for the new unique array
    int* arr = (int*)malloc(sizeof(int) * arr2[0]); //-----------------> Allocate memory for a temporary array to hold unique elements
    arr[0] = arr2[0];                    //---------------> Set the initial size of the temporary array

    // Loop to find unique elements
    for (int i = 1; i <= arr2[0]; i++) {
        int isUnique = 1;                //------------> Flag to check if the current element is unique
        for (int j = 1; j < i; j++) {
            if (arr2[i] == arr2[j]) {    //-------------> Check if the current element has appeared before
                isUnique = 0;            //-------------> Set the flag to 0 if the element is not unique
                break;                   //-------------> Exit the inner loop
            }
        }
        if (isUnique) {                  //-------------> If the element is unique
            arr[count++] = arr2[i];      //-------------> Copy the element to the temporary array and increment the count
        }
    }
    arr2[0] = count - 1;                 //-------------> Update the size of arr2 to reflect the number of unique elements
    arr2 = (int*)realloc(arr2, count * sizeof(int)); //--------------> Reallocate memory for arr2 based on the new size
    for (int i = 1; i <= arr2[0]; i++) {
        arr2[i] = arr[i];                //-----------> Copy unique elements from the temporary array back to arr2
    }
    display(arr2);                       //-----------> Display the array with unique elements
    free(arr);                           //-----------> Free the memory allocated for the temporary array
}

// Function to create a palindrome array
void palindrome(int* arr) {
    int size = arr[0] * 2;               //--------> Calculate the new size for the palindrome array
    int* newArr = (int*)malloc(size * sizeof(int)); //----------> Allocate memory for the palindrome array
    if (newArr == NULL) {                //------------> Check if memory allocation failed
        printf("Memory allocation failed\n");
        return;
    }

    int j = 1;                           //--------------> Initialize index for the new array
    // Copy original elements to the new array
    for (int i = 1; i <= arr[0]; i++) {
        newArr[j++] = arr[i];
    }
    // Append reversed elements to the new array
    for (int i = arr[0]; i > 0; i--) {
        newArr[j++] = arr[i];
    }

    arr[0] = size;                       //-------------> Update the original array size
    arr = (int*)realloc(arr, (size + 1) * sizeof(int)); //---------------> Reallocate memory for the original array
    if (arr == NULL) {                   // Check if memory reallocation failed
        printf("Memory reallocation failed\n");
        free(newArr);                    //----------> Free the new array memory
        return;
    }

    // Copy palindrome elements back to the original array
    for (int i = 1; i <= size; i++) {
        arr[i] = newArr[i];
    }

    display(arr);                        //-----------> Display the palindrome array
    free(newArr);                        //-----------> Free the memory allocated for the palindrome array
}

// Function to sort an array using bubble sort
void sort(int* arr) {
    int temp = 0;                        //-----------> Temporary variable for swapping
    // Bubble sort algorithm
    for (int i = 1; i <= arr[0]; i++) {
        for (int j = i + 1; j <= arr[0]; j++) {
            if (arr[i] > arr[j]) {       //-------------> If the current element is greater than the next element
                temp = arr[i];           //-------------> Swap the elements
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    display(arr);                        //-------------> Display the sorted array
}

int main() {
    int arr1[11];                        
    arr1[0] = 10;                       
    int* arr2 = (int*)malloc(sizeof(int) * (arr1[0] + 1)); //-------------> Allocate memory for another array arr2

    // Get elements from the user
    for (int i = 1; i <= arr1[0]; i++) {
        printf("Enter your element %d for the array: ", i);
        scanf("%d", &arr1[i]);           //----------------> Read element from user and store in arr1
    }

    // Perform various operations on the array
    printf("First Occurrences of 3 and after: ");
    firstOccurence(arr1, arr2);          //------------> Find and display first occurrences of 3 and elements after it
    printf("Unique Numbers: ");
    findUnique(arr2);                    //-----------> Find and display unique elements
    printf("The palindrome: ");
    palindrome(arr2);                    //-----------> Create and display a palindrome array
    printf("Bubble sort: ");
    sort(arr2);                          //-----------> Sort and display the array

    free(arr2);                          // ----------> Free the allocated memory for arr2
    return 0;                            // Return 0 to indicate successful execution
}


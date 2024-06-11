//Function Specification: You are tasked with creating a program that helps find the missing number in an array of consecutive integers. 
// Your program should take an array of integers as input and 
// determine the missing number within the consecutive sequence.

 

// Requirement: Implement a function that would return the missing number from the collection.

#include <stdio.h>

int findMissingNumber(int arr[], int size) {
    int expectedSum = (size + 1) * (size + 2) / 2;  // Sum of the first (n+1) natural numbers
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    
    for (int i = 0; i < size; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    int missingNumber = findMissingNumber(arr, size);
    printf("The missing number is: %d\n", missingNumber);

    return 0;
}

//credits: Exam in codechum Premid i think 
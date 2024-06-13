#include <stdio.h>



int firstOcc(int arr[], int l, int h, int x) {   //------>> Function to find the first occurrence of an element in a sorted array

    // Base case: If the array is empty or the element is not present
    if (h >= l) {
        int mid = (l + h) / 2;
        
        // Check if the middle element is the target and it's not the first element or the target is greater than the previous element
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x) {
            return mid;
        } 
        // If the target is greater than the middle element, continue searching in the right half
        else if (x > arr[mid]) {
            return firstOcc(arr, mid + 1, h, x);
        } 
        // Otherwise, continue searching in the left half
        else {
            return firstOcc(arr, l, mid - 1, x);
        }
    }
    
    return -1; // ---------------- >> Element not found
}


int lastOcc(int arr[], int n, int l, int h, int x) {  //---------------->> Function to find the last occurrence of an element in a sorted array
    
    if (h >= l) {
        int mid = (l + h) / 2;
        
        
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x) {
            return mid;
        } 
        
        else if (x < arr[mid]) {
            return lastOcc(arr, n, l, mid - 1, x);
        } 
        
        else {
            return lastOcc(arr, n, mid + 1, h, x);
        }
    }
 
    return -1;
}


int countOccurrences(int arr[], int n, int x) {  // ---------------->>Function to count the occurrences of an element in a sorted array
   
    int idxFirst = firstOcc(arr, 0, n - 1, x);     // --------------->> Find the first occurrence of the element
    
    // If the element was not found, return -1
    if (idxFirst == -1) {
        return -1;
    }
    
    // Find the last occurrence of the element
    int idxLast = lastOcc(arr, n, idxFirst, n - 1, x); // ---------->> Find the last occurrence of the element
    
    
    return idxLast - idxFirst + 1;// -------------->>Calculate and return the count of occurrences
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 2, 3}; 
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
   
    int occurrences = countOccurrences(arr, n, x); // ------------>>> count the occurrences 
    
    // Print the result
    printf("Number of occurrences of %d: %d\n", x, occurrences);
    return 0;
}
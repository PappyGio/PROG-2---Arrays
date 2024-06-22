#include <stdio.h>

//Function to merge nums1 and nums2 into nums1 in non-decreasing order
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    

    // -- >>> Initialize pointers 
    int p1 = m -1; // -------->>>>>>Pointer for the last element in the initialized part of nums 1
    int p2 = n - 1; // ------->>>>>> Pointer for the last element in nums2.
    int p = m + n - 1; // ----->>>>> Pointer for the last element in the final merged array.



    //Merge nums1 and nums2 from the end 

    while(p1 >= 0 && p2 >=0){
        if(nums1[p1] >nums2[p2]){
            nums1[p] = nums1[p1];  // >>>>>>> Copy nums1[p1] t nums1[p]
            p1--;                  // >>>>>>> move p1 pointer to the left
        }else{
            nums1[p] = nums2[p2]; // >>>>>>>> Copy nums2[p2] to nums1[p]
            p2--;                 // >>>>>>>> move p2 pointer left
        }
        p--; //Move p pointer left
    }
    //if there are remaining elements in num2, copy them
    while(p2 >= 0){
        nums1[p] = nums2[p2]; // >>>>>>>>> Copy nums2[p2] to nums1[p]
        p2--;                 // >>>>>>>>> Move p2 pointer left
        p--;                  // >>>>>>>>> Move p pointer left  
    }

    //Note: no need to copy remaning elements from num1 since they are already in place 
}

//Main function 

int main(){
    int nums1[10] = {1, 2, 3, 0, 0, 0,}; // initialize nums1 with extra space for num2 elements
    int nums2[3] = {2, 5, 6};            // SOrted nums2 array
    int m = 3, n = 3;                    //Sizes of nums1 and nums2

    merge(nums1, 10, m, nums2, 3, n);   // >>>>>>>> Merge nums2 into nums1



    printf("Merged Array: ");
    for(int i = 0; i < m + n; i++){
        printf("%d ", nums1[i]); // ------>>>>>>> Print each element of the merged array 
    }
    printf("\n");

    return 0;
}
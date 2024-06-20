#include<stdio.h>

/*Function to remove all occurrences of 'val' in 'nums' and 
return the count of elements not equal to 'val
*/

int removeElement(int *nums, int numsSize, int val){
    int k = 0; // ------->>> pointer to keep track of the position 
            // for non-val elements


        for(int i= 0; i < numsSize; i++){
            if(nums[i] !=val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k; // =-------->> Return the count of elements not equal to val.
}

int main(){
    int nums[] = {3,2,2,3,4,2,5};
    int val = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int k = removeElement(nums, numsSize, val);


    printf("The number of elements not equal to %d is: %d\n", val, k);
    printf("The modified array is: ");
    for(int i = 0; i < k; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
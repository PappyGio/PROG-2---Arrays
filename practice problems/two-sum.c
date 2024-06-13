//Function specification: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//The returned array must be malloced, assume caller calls free().
//You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include<stdio.h>

//function 
int*twoSum(int*nums, int numsSize, int target){

    int*result = (int*)malloc(2 * sizeof(int)); //allocate memory for the result array

    //Find the two elements that sum up to the target

    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i + 1; j<numsSize; j++){
            if(nums[i] + nums[j] == target){

                //Store the indices in the result array

                result[0] = i; 
                result[1] = j;

                return result;  //Return the result array
            }
        }
    }
    //if no pair is found, return NULL or handle the error accordingly
    return NULL;
}

//Example

int main(){
    int nums[] = {2,7,11,15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;


    int* result = twoSum(nums, numsSize, target);
    if(result!= NULL){
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);  //calls free
    }else{
        printf("No comment.\n");
    }

    
return 0;
}
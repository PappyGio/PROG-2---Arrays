#include<stdio.h>

//Function to calculate the sum of each elements in the array
int calculatesum(int arr[1], int size){
    int sum = 0;

    //iterate to the array and add each element to the sum

    for(int i = 0; i < size; i++){
        sum +=arr[i];
    }
    return sum;
    
}

int main(){
    //Declare variables
    int numElements, sum;

    //ask the user to enter the number of elements 
    printf("Enter the number of elements: ");
        scanf("%d", &numElements);

    //if user is inputting 0 
    if(numElements == 0){
        printf("Sum of elements: 0\n");
        return 0;
    }


    //Declare an array of integers
    int arr[numElements];

   //if only one elements is allowed
    if(numElements == 1){
        printf("Enter element: ");
        scanf("%d", &arr[0]);
    }

    //otherwise if all elements 

    else{
        printf("Enter the elements:\n");
        for(int i = 0; i < numElements; i++){
            scanf("%d", &arr[i]);
        }
    }

    //calculate the sum of the elements in the array 
    sum = calculatesum(arr, numElements);

    //print the sum
    printf("Sum of elements: %d\n", sum);

    return 0;
    
}
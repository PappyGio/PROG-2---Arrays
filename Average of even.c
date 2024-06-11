//Function Specification: Write a function that calculates the average of even numbers in a collection. 
// The program should prompt the user to enter the number of elements and the values of each element. 
// The program should then display all the elements and the total of the even numbers and the average.

#include<stdio.h>
#include<math.h>

void calculateEvenNumbers(int arr[], int size, int *sum, float *average){ // function to calculate the sum and average of even numbers 
    int evenCount = 0;

    *sum = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] % 2  == 0){
            *sum += arr[i];
            evenCount++;
        }
    }

    if(evenCount > 0){
        *average = (float)(*sum) / evenCount;
    }else {
        *average = NAN;
    }
}


int main(){
    int numElements;

    //Prompt the user to enter the number of elements
    printf("Enter how many values: ");
    scanf("%d", &numElements);

    if (numElements == 0){
        printf("List {}\n");
        printf("The sum of even is 0.\n");
        printf("The average of even is -nan.\n");
        return 0;
    }

    int elements[numElements]; // Initialize an array to store the elements 

    for(int i = 0; i <numElements; i++){ //Loop to get elements from the user
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &elements[i]);
    }

    int sum;
    float average;
    calculateEvenNumbers(elements, numElements, &sum, &average); //calculate the sum and average of even numbers 

    //print the list 
    printf("List {");
    for(int i = 0; i < numElements; i++){
        printf("%d", elements[i]);
        if(i < numElements - 1){
            printf(", ");
        }
    }
    printf("}\n");


    //Print the sum and average of even numbers
    printf("The sum of even is %d.\n",sum);
    if(isnan(average)){
        printf("The average of even is -nan.\n");
    }else{
        printf("The average of even is %.2f.\n", average);
    }
    return 0;
}

//credits: Exam in codechum Premid i think 
//FUNCTIONS SPECIFICATIONS: Write a function that calculates the total of odd numbers in a collection. 
// The program should prompt the user to enter the number of elements and the values of each element. 
// The program should then display all the elements and the total of the odd numbers.

 
#include<stdio.h>

//Function to calculate the sum of odd numbers

int sumofOdds(int arr[], int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 !=0){
            sum += arr[i];
        }
    }
    return sum;
}

int main(){
    int numElements;

    //Prompt the user to enter the number of elements
    printf("Enter how many values: ");
    scanf("%d", &numElements);

    int elements[numElements]; // Initialize an array to store the elements

    //loop to get elements from the suer 
    for(int i = 0; i < numElements; i++){
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &elements[i]);
    }

    int sum = sumofOdds(elements,numElements); // Calculate then sum of odd elements 

    //printing the list 

    printf("List {");
    for(int i = 0; i<numElements; i++){
        printf("%d", elements[i]);
        if(i<numElements - 1){
            printf(", ");

        }
    }
 printf("}\n");

 printf("The sum of odd is %d.\n", sum); // print the sum of odd elements 

 return 0;
}
//credits: Exam in codechum Premid i think 
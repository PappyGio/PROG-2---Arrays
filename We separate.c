#include<stdio.h>
#include<stdlib.h>

//function to get the number of elements from the user 
int get_number(){
    int count;
    printf("Enter how many values: ");
    scanf("%d", &count);
    return count;
}


//Function to get elements from the user and store them
void get_elements(int *arr, int count){
    for(int i = 0; i < count; i++){
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

//Function to filter elements based on the parity of the first element 

void filter_parity(int *arr, int count, int *result, int *result_count){
    int first_element = arr[0];
    int is_even = (first_element % 2 == 0);

    *result = 0;
    for(int i = 0; i < count; i++){
        if((arr[i] % 2 == 0) == is_even){
            result[*result_count] = arr[i];
            (*result_count)++;
        }
    }

}

//Function to print an array 

void print(int *arr, int count){
    printf("{");
    for(int i = 0; i < count; i++){
        if(i > 0 ){
            printf(", ");
        }
        printf("%d", arr[i]);
    }
    printf("}\n");
}


int main(){
    //Get the number of elements
    int count = get_number();

    //Allocate memory for the elements array

    int *arr = (int *)malloc(count * sizeof(int));

    //get the elements from the user 
    get_elements(arr, count);


    //Allocate

    int *result = (int *)malloc(count * sizeof(int));
    int result_count;


    //filter the elements by parity

    filter_parity(arr,count,result,&result_count);

    //Print the original array
    printf("Original ");
    print(arr, count);


    //Print the new array  
    printf("New ");
    print(result, result_count);



    free(arr);
    free(result);

    return 0;
}

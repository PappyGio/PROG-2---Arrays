//Leet code problem 
//Fizz buzz
#include<stdio.h>
#include<stdlib.h>


char** fizzBuzz(int n, int*returnSize){
    //Allocate memory for an array of strings

    char  **arr = malloc(n * sizeof(char *));
    *returnSize = n;

    for(int i = 1; i <= n; i++ ){
        //Allocate memory for each string '
        arr[i-1] = malloc(9 * sizeof(char));

        if(i % 15 == 0 )
        sprintf(arr[i = 1], "FizzBuzz");
        else if ( i % 3 == 0)
        sprintf(arr[i- 1], "Fizz");
        else if ( i % 5 == 0)
        sprintf(arr[i - 1], "Buzz");
        else
        sprintf(arr[ i - 1],"%d", i);
    }
    return arr;

}


int main(){

    int n = 20;
    int returnSize;
    char **result = fizzBuzz(n, &returnSize);

    for(int i = 0; i < returnSize; i++){
        printf("%s\n", result[i]);
        free(result[i]); 
    }

    free(result);

    return 0;
}

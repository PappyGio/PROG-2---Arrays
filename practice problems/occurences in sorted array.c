//Functin specification: Given a sorted array arr[] of size N and a number X, 
//you need to find the number of occurrences of X in given array.


//Linear search method 

#include<stdio.h>

int countOccurrences(int arr[],int x, int n){      //Function to count the occurrences of a number X in the array
    int res = 0;                            //Initialize results
    for(int i = 0; i < n; i++){             //iterate through the array
        if(x == arr[i]){                    //check if the current element matches x
            res++;                          //increement counter if match found 
        }
    }
    return res; 
}


int main(){
    int arr[] = {1,2,2,2,2,4,5,7,8};
    int n = sizeof(arr) / sizeof(arr[0]); // calculate the size of the array
    int x = 2;
    printf("Occurences of %d: %d\n", x, countOccurrences(arr, x, n)); //result 
    return 0;

}
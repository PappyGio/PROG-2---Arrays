#include<stdio.h>

//sum of the odd integers and even integers saved at the last index of the array.
//Pointer arithmetic only


void display(int *arr){
 int choice, flag = 0;

    do {
        printf("Choose display:\n1. Original array with added sum\n2. Array with Even numbers\n3. Array with Odd Numbers\n Answer Here: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n Original array.  \n");
                for(int i = 0; i <= 8; i++){
                    printf("%d  ", *(arr+i));
                }
                break;

            case 2:
                printf("Array with even numbers \n");
                for(int i = 0; i <= 8; i++){
                    if(*(arr + i) % 2 == 0) {
                    printf("%d", *(arr + i));
                }
                }
                break;

            case 3:
                printf("Array with odd numbers \n");
                for(int i = 0; i <= 8; i++ ){
                    if(*(arr + i) % 2 != 0){
                    printf("%d", *(arr + i));
                    }
                }
            default:
                break;
        }
        flag =1;
    }while(!flag);
}

//splitting the array into odd and even
//if those two array into  the same size add the contents of both the arrays to each other 
//if not return an integer zero to the main function 

int main(){
    int arr[8], sum; // odd or even or both integers printing function should be separated 
    
    printf("Input 8 elements: \n");
    for(int i = 0; i < 8; i++){
        scanf("%d", &*(arr+i));
        sum += *(arr + i);
    }
    *(arr+8) = sum;
    
    display(arr);
}
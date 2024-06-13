#include<stdio.h>


//functions 
void populate(int arr[], int count){ ///--->>> populate an array
    int i= 0;
    for(i = 0; i < count; i++){
        printf("Enter the value [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void add( int arr[], int *count){ // --------->> Append at the end
    int toAdd;
    scanf("%d", &toAdd);
    arr[*count] = toAdd;
    (*count)++;
}


void multiply(int arr[], int count){ //-------->>>if even or odd
    int i;
    for(i = 0; i < count; i++){
        if(arr[i]%2==0){
            arr[i] = arr[i] * 2;
        }
        else{
            arr[i] = arr[i] * 3;
        }
    }
}

//main 

int main(){
    int arr[20];
    int count = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &count);

    
    populate(arr, count);
    add(arr, &count);
    multiply(arr, count);


    
    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

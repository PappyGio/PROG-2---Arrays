#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *revArr(int arr[], int size);

int main(){
    int i, size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    for(i=0;i<size;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", arr+i);
    }
    
    printf("Original array: [");
    for(i=0;i<size;i++){
        (i==0)? printf("%d", arr[i]):printf(", %d", arr[i]);
    }
    
    int *rev = revArr(arr, size);
    
    printf("]\nReverse array: [");
        for(i=0; rev[i] >= 0 ;i++){
            (i==0)? printf("%d", rev[i]):printf(", %d", rev[i]);
        }
    printf("]");
    free(rev);
    return 0;
}

int *revArr(int arr[], int size){
    int i, j;
    size++;
    int newarr[size];
    for(i=size-2, j=0;i>=0 && j<size-1;i--, j++){
            newarr[j] = arr[i];
    }
    newarr[size-1] = -1;
    int *reved = (int*) malloc(size* sizeof(int));
    memcpy(reved, newarr, size*sizeof(int));
    return reved;
 }
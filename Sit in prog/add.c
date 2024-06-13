#include<stdio.h>

int main(){
    int arr[20] = {1,2,3,4,5,};
    int count  =5;

    add(arr);

    printf("%d", arr[5]);

    return 0;
}


//function

void add(int *arr){
    int sum = arr[0] + arr[1];
    printf("%d", sum);
    arr[5] = 6;

}
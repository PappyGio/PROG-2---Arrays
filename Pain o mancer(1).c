#include <stdio.h>
#include <stdlib.h>

void groupClosestPairs(int arr[], int size) {
  int i, j, flag=0, pairs, ctr, temp;
  
  printf("Closest pairs: \n");
  if(size%2==0){
      flag = 1;
      pairs = size/2;
  }else{
      pairs = (size+1)/2;
  }
  for(i = 0; i < size; i++){
      for(j = 0; j < size; j++){
          if(arr[i]<arr[j]){
              temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
          }
      }
  }
  if(flag == 1){
      for(j = 0; j<size; j++){
          if((j+1)%2!=0){
              printf("(%d, ", arr[j]);
          }else{
              printf("%d)\n", arr[j]);
          }
      }
  }
  else{
      for(j = 0; j <size; j++){
          if(j == size-1){
              printf("(%d, -)", arr[j]);
          }else{
              if((j+1)%2!=0){
                  printf("(%d, ", arr[j]);
              }else{
                  printf("%d)\n", arr[j]);
              }
          }
      }
  }
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: \n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    groupClosestPairs(arr, n);

    return 0;
}

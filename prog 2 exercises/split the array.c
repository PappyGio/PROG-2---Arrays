#include<stdio.h>


//Function Prototype
void printRes(int[], int,int,int);


void printRes(int arr[], int even,int odd, int num){
    int i, a1[odd], a2[even];

    int ctr1 =0, ctr2 = 0;
    for(i = 0; i < 8; i++){
        if(*(arr+i)%2!=0){
            *(a1 + ctr1)=*(arr+i);
            ctr1++;
        }else{
            *(a2 + ctr2)=*(arr+i);
            ctr2++;
        }
    }
    if(num == 0){
        for(i = 0; i <8; i++){
            printf("%d ", *(arr + i));
        }
        printf("\nsum = %d\n", *(arr + 8));
    }

    else if(num == 1){
        for(i = 0; i < odd; i++){
            printf("%d ", *(a1+i));
        }
    }

    else if(num == 2){
        for(i = 0; i < even; i++){
            printf("%d ", *(a2+i));
        }
    }

    else{
        printf("INVALID MY FRIEND\n");
    }

    if(odd == even){
        printf("\n Both arrays have the same size:\n");
        for(i=0; i<odd; i++){
            printf("%d ", *(a1 + i) + *(a2 + i));
        }
    }else{
        printf("\n\n0");
    }
}





int main(){
    int i, a[9], odd =0, even = 0, disp;


    a[8] = 0;

    printf("Input 8 integers: ");

    for(i = 0; i<8; i++){
        scanf("%d", &a[i]);
        if(a[i]%2==0){
            even++;
        }else{
            odd++;
        }
        a[8]+=a[i];
    }
    printf("----------Welcome my friend----------\n");
    printf("----------CHOOSE HERE!----------\n");
    printf("ODD[1], EVEN[2], BOTH[0]:  ");
    scanf("%d", &disp);

    printf("\n");

    printRes(a, even, odd, disp);
}



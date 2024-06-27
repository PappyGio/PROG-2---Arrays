/*
Given a string input determine if the given string is a palindrome or not 

Example of palindrome 
Mom
Dad
Pop
Nurses Run
Radar
ROtator
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function to check if a string is a palindrome 
int isPalindrome(char str[]){
    int left = 0;
    int right = strlen(str) - 1;


    while (left < right){
        //Move left index to the right as long as its not alphanumeric
        while (left < right && !isalnum(str[left])){
            left++;
        }
        //Move right index to the left as long as its not alphanumeric 
        while(left < right && !isalnum(str[right])){
            right--;
        }
        //Compare characters 
        if (tolower(str[left]) != tolower(str[right])){
            return 0;//Not a palindrome
        }
        left++;
        right--;
    }
    return 1; //is a palindrome 
}


int main(){
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);


    //Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
    
    if(isPalindrome(str)){
        printf("String is palindrome \n");
    }else{
        printf("Not palindrome \n");
    }

    return 0;
}
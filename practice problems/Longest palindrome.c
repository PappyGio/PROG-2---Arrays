// Given a string s, return the longest palindromic substring in s.
//Problem in leet code


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Helper function to expand around the center and the find the length of the palindrome 

int expandAroundCenter(char *s, int left, int right){
    int L = left, R = right;
    int len = strlen(s);

    //Expand while the characters at L and R are equal and within bounds

    while(L >= 0 && R < len && s[L] == s[R]){
        L--;
        R++;
    }
    return R-L-1; //Return the length of the palindrome 
}

//Main function to find the longest palindromic substring 

char *longestPalindrome(char *s){
    int len  = strlen(s); // get the length of the string 
    if (len == 0)return ""; //if the string is empty, return an empty string 
    int start = 0, end = 0; //Initialize start and end indices for the longest palindrome. 

    //Iterate over each character in the string

    for(int i = 0; i < len; i++){
        int len1 = expandAroundCenter(s, i, i); // check for palindromes with a single center( odd-length palindromes)
        int len2 = expandAroundCenter(s, i, i + 1); // check for double length (even-length palindromes)
        int maxLen = len1 > len2 ? len1 : len2; // get the maximum length of the two palindromes


        if (maxLen > end - start){ // update the start and end indices if a longer palindrome is found 
            start  = i - (maxLen - 1 ) / 2;
            end = i +  maxLen / 2;
        }
    }
   
    int resultLen = end - start + 1; //Calculate the length of the longest palindrome
    char *result = (char *)malloc(resultLen + 1); //Allocate memory for the result substring 
    strncpy(result, &s[start], resultLen);
    result[resultLen] = '\0';
    return result;
}


// main 


int main(){
    char s[1001]; //Array to store the input string up to 1000 characters 



    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    //Remove newline character is present 

    size_t len = strlen(s);
    if(len > 0 && s[len-1] == '\n'){
        s[len-1] = '\0';
    }

    char *result = longestPalindrome(s); // Find the longest palindromic substring 


    printf("Longest Palindromic substring: %s\n", result);

}
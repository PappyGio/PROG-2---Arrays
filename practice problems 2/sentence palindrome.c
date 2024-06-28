/* FUNCTION SPECIFICATION:
Create a program & a function that inputs 
a user a sentence and  finds the palindrome in the sentence 
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>


#define MAX_LEN 100

int ispalindrome(char *str){
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len - i - 1]){
            return 0;
        }
    }
    return 1;
}

void findpalindrome(char *sentence){
    char word[MAX_LEN];
    int wordindex = 0;
    int palindromefound = 0; // flag top track if palindrome is found 
    for(int i = 0; sentence[i] !='\0'; i++){
        char c = sentence[i];

        if(isalnum(c)){
            word[wordindex++] = tolower(c);
        }else if (wordindex > 0){
            word[wordindex] = '\0';
            if(ispalindrome(word)){
                printf("Palindrome found: %s\n", word);
                palindromefound = 1;
            }
            wordindex = 0;
        }
    }


    //Check last word 
    if (wordindex > 0){
           word[wordindex] = '\0';
            if(ispalindrome(word)){
              printf("Palindrome found: %s\n", word);  
            }
    }
    if(!palindromefound){
        printf("No palindrome found ");
    }

}

int main(){
    char sentence[MAX_LEN];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LEN, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; //Remove newline character if present 

    findpalindrome(sentence);

    return 0;
    


}

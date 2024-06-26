#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to censor the vowels in a curse word or phrase.  
void censorVowels(char *phrase){
    char vowels[] = "aeiouAEIOU";
    int length = strlen(phrase);

    for(int i = 0; i < length; i++){
        if(strchr(vowels, phrase[i])){
            phrase[i] = '*';
        }
    }
}

// Main function 
int main(){
    char phrase[100];
    printf("Enter a phrase: ");
    fgets(phrase, sizeof(phrase), stdin);

    // Remove newline character if present
    phrase[strcspn(phrase, "\n")] = '\0';

    censorVowels(phrase);

    printf("Censored phrase: %s\n", phrase);

    return 0;
}

//Create a function that efficiently removes all whitespace characters from a given string returning as a new string.
//The program should prompt the user to enter a string and then process it, eliminating all spaces, tabs, and line breaks. 
//Finally, it should display the modified string as the output.
 

//You can use any string and ctype functions.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void removeWhitespace(const char *input, char *output){
    int i = 0, j = 0;

    while(input[i] != '\0') {
        if(!isspace(input[i])) { // chjeck if the character is not a whitespace
            output[j++] = input[i];
        }
        i++;
    }
    output[j] = '\0'; // null terminate the output string 
}

int main(){
    char input[1000];//buffer to store the input string
    char output[1000];//buffer to store the modified 

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); //Reads the input string including the spaces 

    //Remove the newline character if present 
    size_t len=strlen(input);
    if(len > 0 && input[len - 1] == '\n'){
        input[len - 1] = '\0';
    }

    

    removeWhitespace(input, output); //process the string to remove whitespace

    printf("Modified string: %s\n", output);

    return 0;
}
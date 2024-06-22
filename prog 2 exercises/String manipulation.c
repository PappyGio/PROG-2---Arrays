/* 
Input first name 
input middle name 
input final name 

print in alphabetical order 
sort each string individually
compress string 

ima opitmize it 
NO USE BUBBLE SORT FCK 
BUT USING BUBBLE SORT 

NOT YET FINISH

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>


//Function to sort the characters of a string in alphabetical order (case-insensitive)
void sortstring(char str[]){
    int n = strlen(str); // ---------->Get the length of the string 
    char temp; // -----------> temporary variable for swapping

    //bubble sort to sort characters 
   for(int i = 0; i < n-1; i++){ // --------> Outer loop to control passes

        for(int j = i + 1; j < n; j++){ // -------> Inner loop to compare elements
            if(tolower(str[i]) > tolower(str[j])){ // ----------> Inner loop to compare elements
                temp = str[i]; // ------------> Store the value of str[i] in temp
                str[i] = str[j]; //-----------> Assign the value of str[j] t str[i]
                str[j] = temp; // ------------> Assign the value of temp to str[j]
            }
        }
    }
}

//Function to sort and print each names's characters in alphabetical order
void sortcharacters(char fname[], char lname[], char mname[]){ // 
    
    //sort each string individually using the sorting function 
    sortstring(fname);
    sortstring(lname);
    sortstring(mname);


    //print the sorted strings
    printf("Sorted characters in the first name: %s\n", fname);
    printf("Sorted characters in the last name: %s\n", lname);
    printf("Sorted characters in the middle name: %s\n", mname);
    
    
}

//Function to print the names in alphabetical order
void Alphabetical(char* fname, char* lname, char* mname){ 

    char *names[] = {fname, lname, mname}; //------------>> Array to hold the names
    char *temp; // --------------------------->>Temporary variable for swapping


    //bubble sort that sort names
    for(int i = 0; i < 2; i++){ // ----------->> Outer loop control passes
        for(int j = i + 1; j < 3; j++){ //-------------->> Inner loop to compare elements
            if(strcasecmp(names[i], names[j]) > 0){ //------------------>> Compare strings in a case-insensitive manner

            //Swap names if they are in the wrong order
                temp = names[i]; // ------------------->>Store the value of names[i] in temp
                names[i] = names[j]; // --------------->>Assign the value of names[j] to  names[i]
                names[j] = temp; // ------------------>>Assign the value of temp to names[j]
            }
        }
    }
    //print
    printf("print in alphabetical order: \n");
    for(int i = 0; i < 3; i++){ // ------------->> loop through the sorted names 
        printf("%s\n", names[i]);
    }
}

//Function to compress a string by counting consecutive characters
void compress(char str[], char compressed[]){
    int n = strlen(str); // ---------------->> Getting the length of the string 
    int count, index = 0;// ---------------->> Initialize count and index

//   Iterate through the string
    for(int i = 0; i < n; i++){
        count = 1; // --------------->> Initialize count for the current character

        while(i < n - 1 && str[i] ==  str[i + 1]){ // --------------->> check for consecutive characters 
            count++;// --------------------------------->> increment count for each occurrence
            i++; // ------------------------------------>> move to the next character
        }
        //append the character  to the compressed string

        compressed[index++] = str[i];

        //append the count to the compressed string 

        index += sprintf(&compressed[index], "%d", count);
    }
        compressed[index ]= '\0'; //---------------->>>>>> Null terminate the compress string 
}


//Function to compress a string 
void sortcompressstring(char str[], char compressed[]){
//Sort the characters in the string 
sortstring(str);
compress(str, compressed);// Compress the sorted string 
}


int main(){
    char fname[50];
    char lname[50];
    char mname[50];
    char compressed[150]; // Array to hold the compressed string 
    


    printf("Enter your First name: ");
    scanf("%s", fname);
    printf("Enter your Last name: ");
    scanf("%s", lname);
    printf("Enter your middle name: ");
    scanf("%s", mname);

      Alphabetical(fname,lname, mname); // calling function 
   sortcharacters(fname, lname, mname); // calling function 



    //Input the string to compress
    printf("Enter a string to compress: ");
    char str[100]; // ----------------->>Array to hold the input string 
    scanf("%99s", str); // ------------>>Read a string with a limit of 99 characters to avoid buffer overflow

    //Compress the string
    compress(str, compressed); // calling function 
    printf("Compressed string: %s\n", compressed);


    //Sort and compress the stirng 
    sortcompressstring(str, compressed); // ------>>>>> calling function 
    printf("Sorted and compressed string: %s\n", compressed);
    return 0;
}


/*

ADDITIONAL NOTES

sortstring function:
1. the function sort the characters of a string using bubble sort 
2. it uses "tolower" to ensure the comparison is case insensitive 

sortcharacters function:

1. The function sorts each provided name(first, last, and middle ) using sortstring 
2. it then prints each sorted name.

Alphabetical function:

1. The function sorts the given names in alphabetical order still using the bubble sort.
2. It uses strcasecmp for case-insensitive comparison then prints the names

compress function:
1. The function compresses a string by counting consecutive characters and appending the character and its count to the compressed string.
2. it iterates through the string, counts consecutive characters and constructs the compressed string.

sortcompressstring function:

1. The function first sorts the characters in the string using sortstring
2. it then compresses the sorted using compress.


*/

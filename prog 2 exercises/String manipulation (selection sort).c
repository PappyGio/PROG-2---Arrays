#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sort the characters of a string in alphabetical order (case-insensitive)
void sortstring(char str[]) {
    int n = strlen(str); // Get the length of the string 
    char temp; // Temporary variable for swapping

    // Selection sort to sort characters 
    for (int i = 0; i < n - 1; i++) { // Outer loop to control passes
        int min_idx = i; // Initialize the index of the minimum element
        for (int j = i + 1; j < n; j++) { // Inner loop to find the minimum element
            if (tolower(str[j]) < tolower(str[min_idx])) { // Compare elements
                min_idx = j; // Update the index of the minimum element
            }
        }
        // Swap the found minimum element with the first element
        temp = str[i]; // Store the value of str[i] in temp
        str[i] = str[min_idx]; // Assign the value of str[min_idx] to str[i]
        str[min_idx] = temp; // Assign the value of temp to str[min_idx]
    }
}

// Function to sort and print each name's characters in alphabetical order
void sortcharacters(char fname[], char lname[], char mname[]) {
    // Sort each string individually using the sorting function 
    sortstring(fname);
    sortstring(lname);
    sortstring(mname);

    // Print the sorted strings
    printf("Sorted characters in the first name: %s\n", fname);
    printf("Sorted characters in the last name: %s\n", lname);
    printf("Sorted characters in the middle name: %s\n", mname);
}

// Function to print the names in alphabetical order
void Alphabetical(char* fname, char* lname, char* mname) {
    char* names[] = { fname, lname, mname }; // Array to hold the names
    char* temp; // Temporary variable for swapping

    // Selection sort to sort names
    for (int i = 0; i < 2; i++) { // Outer loop to control passes
        int min_idx = i; // Initialize the index of the minimum element
        for (int j = i + 1; j < 3; j++) { // Inner loop to find the minimum element
            if (strcasecmp(names[j], names[min_idx]) < 0) { // Compare strings in a case-insensitive manner
                min_idx = j; // Update the index of the minimum element
            }
        }
        // Swap the found minimum element with the first element
        temp = names[i]; // Store the value of names[i] in temp
        names[i] = names[min_idx]; // Assign the value of names[min_idx] to names[i]
        names[min_idx] = temp; // Assign the value of temp to names[min_idx]
    }

    // Print the sorted names
    printf("Names in alphabetical order: \n");
    for (int i = 0; i < 3; i++) { // Loop through the sorted names 
        printf("%s\n", names[i]);
    }
}

// Function to compress a string by counting consecutive characters
void compress(char str[], char compressed[]) {
    int n = strlen(str); // Getting the length of the string 
    int count, index = 0; // Initialize count and index

    // Iterate through the string
    for (int i = 0; i < n; i++) {
        count = 1; // Initialize count for the current character

        while (i < n - 1 && str[i] == str[i + 1]) { // Check for consecutive characters 
            count++; // Increment count for each occurrence
            i++; // Move to the next character
        }

        // Append the character to the compressed string
        compressed[index++] = str[i];

        // Append the count to the compressed string 
        index += sprintf(&compressed[index], "%d", count);
    }
    compressed[index] = '\0'; // Null terminate the compressed string 
}

// Function to sort and compress a string 
void sortcompressstring(char str[], char compressed[]) {
    // Sort the characters in the string 
    sortstring(str);
    // Compress the sorted string 
    compress(str, compressed);
}

int main() {
    char fname[50];
    char lname[50];
    char mname[50];
    char compressed[150]; // Array to hold the compressed string 

    printf("Enter your First name: ");
    scanf("%s", fname);
    printf("Enter your Last name: ");
    scanf("%s", lname);
    printf("Enter your Middle name: ");
    scanf("%s", mname);

    Alphabetical(fname, lname, mname); // Call the function to print names in alphabetical order
    sortcharacters(fname, lname, mname); // Call the function to sort characters in each name 

    // Input the string to compress
    printf("Enter a string to compress: ");
    char str[100]; // Array to hold the input string 
    scanf("%99s", str); // Read a string with a limit of 99 characters to avoid buffer overflow

    // Compress the string
    compress(str, compressed); // Call the function to compress the string 
    printf("Compressed string: %s\n", compressed);

    // Sort and compress the string 
    sortcompressstring(str, compressed); // Call the function to sort and compress the string 
    printf("Sorted and compressed string: %s\n", compressed);

    return 0;
}

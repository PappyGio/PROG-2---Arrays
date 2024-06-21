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



void sortstring(char str[]){
    int n = strlen(str);
    char temp;

    //bubble sort
   for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(tolower(str[i]) > tolower(str[j])){
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void sortcharacters(char fname[], char lname[], char mname[]){
    
    //sort each string
    sortstring(fname);
    sortstring(lname);
    sortstring(mname);


    //print the sorted strings
    printf("Sorted characters in the first name: %s\n", fname);
    printf("Sorted characters in the last name: %s\n", lname);
    printf("Sorted characters in the middle name: %s\n", mname);
    
    
}

void Alphabetical(char* fname, char* lname, char* mname){ // function to print the names in alphabetical order

    char *names[] = {fname, lname, mname};
    char *temp;
    for(int i = 0; i < 2; i++){
        for(int j = i + 1; j < 3; j++){
            if(strcasecmp(names[i], names[j]) > 0){
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
    //print
    printf("print in alphabetical order: \n");
    for(int i = 0; i < 3; i++){
        printf("%s\n", names[i]);
    }
}

void compress(char str[], char compressed[]){
    int n = strlen(str);
    int count, index = 0;

    for(int i = 0; i < n; i++){
        //Count occurrences of the current character 
        count = 1;
        while(i < n - 1 && str[i] ==  str[i + 1]){
            count++;
            i++;
        }
        //append the character  to the compressed string

        compressed[index++] = str[i];

        //append the count to the compressed string 

        index += sprintf(&compressed[index], "%d", count);
    }
        compressed[index ]= '\0';
}


//Function to compress a string 
void sortcompressstring(char str[], char compre)


int main(){
    char fname[50];
    char lname[50];
    char mname[50];
    char compressed[150];
    


    printf("Enter your First name: ");
    scanf("%s", fname);
    printf("Enter your Last name: ");
    scanf("%s", lname);
    printf("Enter your middle name: ");
    scanf("%s", mname);


    Alphabetical(fname,lname, mname);
   sortcharacters(fname, lname, mname);

    return 0;

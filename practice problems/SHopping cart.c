///Not yet finish still lacking 



//Display stock
//update stock 
//Change price 
//Add to cart 
//Remove cart 
//view cart 

//arrays to be made
//1, display stock 
//2. update stock
//3. change price
//4. add to cart
//5. Remove cart 
//6. view cart
//7.check out 
#include <stdio.h>

void displaystock(char name[][50], int quantity[], float price[], int size) {
    printf("\nIndex\tName\t\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%d\t\t$%.2f\n", i + 1, name[i], quantity[i], price[i]);
    }
}

void updatestock(char name[][50], int quantity[], int size, int index, int newquantity) {
    if (index >= 1 && index <= size) {
        quantity[index - 1] = newquantity;
        printf("Quantity of %s updated to %d.\n", name[index - 1], newquantity);
    } else {
        printf("Invalid index.\n");
    }
}

void changeprice(char name[][50], float price[], int size, int index, float newprice){
      if(index >= 1 && index <= size){
        price[index - 1] = newprice;
        printf("Price of %s updated to $%.2f.\n", name[index-1], newprice);
      }else{
        printf("Invalid index.\n");  
      }
}

void addtocart(){
    
}

int main() {
    char name[][50] = {"Milk Choc", "Dark Choc", "Mint Chocolate", "White Choc", "Peanut Choc"};
    int quantity[] = {60, 42, 29, 60, 38};
    float price[] = {12.00, 25.00, 20.00, 15.00, 8.00};
    int size = sizeof(quantity) / sizeof(quantity[0]); // assuming all arrays have the same size

    char choice;
    printf("Do you want to display the stock? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        displaystock(name, quantity, price, size);
    } else {
        printf("Stock not displayed.\n");
    }

    int index, newquantity;
    printf("Enter the index of the item you want to update: ");
    scanf("%d", &index);
    if (index >= 1 && index <= size) {
        printf("Enter the new quantity for %s: ", name[index - 1]);
        scanf("%d", &newquantity);
        updatestock(name, quantity, size, index, newquantity);
    } else {
        printf("Invalid index.\n");
    }

    // Display updated stock
    printf("\nUpdated Stock:\n");
    displaystock(name, quantity, price, size);



    //change price of an item 
    float newprice;        
    printf("Enter the index of the item whose price you want to update: ");
    scanf("%d", &index);
    if (index >= 1 && index <= size) {
        printf("Enter the new price for %s: ", name[index - 1]);
        scanf("%f", &newprice);
        changeprice(name, price, size, index, newprice);
    } else {
        printf("Invalid index.\n");
    }


    return 0;
}


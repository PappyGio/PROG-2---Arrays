///Not yet finish still lacking 



//Display stock
//update stock 
//Change price 
//Add to cart 
//Remove cart 
//view cart 

//arrays to be made
//1, display stock 
//2. remove cart
//3. view cart 
//4. check out
//5. add to cart 
//6. 
#include <stdio.h>

void displaystock(char name[][50], int quantity[], float price[], int size) {
    printf("\nIndex\tName\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%d\t\t$%.2f\n", i + 1, name[i], quantity[i], price[i]);
    }
}

void updatestock(char name[][50], int quantity[], int index, int newquantity) {
    if (index >= 1 && index <= sizeof(name) / sizeof(name[0])) {
        quantity[index - 1] = newquantity;
        printf("Quantity of %s updated to %d.\n", name[index - 1], newquantity);
    } else {
        printf("Invalid index.\n");
    }
}


void changeprice(){
    
}

int main() {
    char name[][50] = {"Milk Choc", "Dark Choc", "Mint Chocolate", "White Choc", "Peanut Choc"};
    int quantity[] = {60, 42, 29, 60, 38};
    float price[] = {12.00, 25.00, 20.00, 15.00, 8.00};
    int size = sizeof(name) / sizeof(name[0]); // assuming all arrays have the same size

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
    printf("Enter the new quantity for %s: ", name[index - 1]);
    scanf("%d", &newquantity);

    updatestock(name, quantity, index, new_quantity);

    // Display updated stock
    printf("\nUpdated Stock:\n");
    displaystock(name, quantity, price, size);

    return 0;
}

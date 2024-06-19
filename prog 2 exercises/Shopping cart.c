/* still gonna optimize it soon
this is the same one from the practice problem folder */




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
#include <string.h>
#include <stdlib.h>

#define MAX_CART_ITEMS 100



//display menu function 
void displayMenu() {
    printf("\nWELCOME TO GIO SARI SARI STORE\n");
    printf("\nMenu:\n");
    printf("1. Display Stock\n");
    printf("2. Update Stock Quantity\n");
    printf("3. Change Item Price\n");
    printf("4. Add Items to Cart\n");
    printf("5. View Cart\n");
    printf("6. Remove Item from Cart\n");
    printf("7. Proceed to Checkout\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

// Function to display stock horizontally
void displaystock(char name[][50], int quantity[], float price[], int size) {
    printf("\nIndex\tNames\t\t\tQuantities\t\tPrices\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%d\t\t$%.2f\n", i + 1, name[i], quantity[i], price[i]);
    }
}

// Function to update stock quantity
void updatestock(char name[][50], int quantity[], int size, int index, int newquantity) {
    if (index >= 1 && index <= size) {
        quantity[index - 1] = newquantity;
        printf("Quantity of %s updated to %d.\n", name[index - 1], newquantity);
    } else {
        printf("Invalid index.\n");
    }
}

// Function to change the price of an item
void changeprice(char name[][50], float price[], int size, int index, float newprice) {
    if (index >= 1 && index <= size) {
        price[index - 1] = newprice;
        printf("Price of %s updated to $%.2f.\n", name[index - 1], newprice);
    } else {
        printf("Invalid index.\n");
    }
}

// Function to add multiple items to the cart
void addMultipleToCart(char name[][50], int cartQuantity[], float cartPrice[], int *cartSize, char itemNames[][50], int quantities[], float prices[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        for (int j = 0; j < *cartSize; j++) {
            if (strcmp(name[j], itemNames[i]) == 0) {
                cartQuantity[j] += quantities[i];
                printf("Increased quantity of %s to %d.\n", itemNames[i], cartQuantity[j]);
                goto nextItem;
            }
        }
        if (*cartSize < MAX_CART_ITEMS) {
            strcpy(name[*cartSize], itemNames[i]);
            cartQuantity[*cartSize] = quantities[i];
            cartPrice[*cartSize] = prices[i];
            (*cartSize)++;
            printf("Added %d of %s to the cart.\n", quantities[i], itemNames[i]);
        } else {
            printf("Cart is full. Cannot add more items.\n");
            return;
        }
        nextItem:;
    }
}

// Function to remove item from cart
void removeFromCart(char name[][50], int cartQuantity[], float cartPrice[], int *cartSize, int index) {
    if (index >= 1 && index <= *cartSize) {
        for (int i = index - 1; i < *cartSize - 1; i++) {
            strcpy(name[i], name[i + 1]);
            cartQuantity[i] = cartQuantity[i + 1];
            cartPrice[i] = cartPrice[i + 1];
        }
        (*cartSize)--;
        printf("Item removed from the cart.\n");
    } else {
        printf("Invalid index.\n");
    }
}

// Function to display cart contents horizontally and calculate total cost
void viewCart(char name[][50], int cartQuantity[], float cartPrice[], int cartSize) {
    printf("\nCart Contents:\n");
    printf("Index\tNames\t\t\tQuantities\t\tPrices\n");
    printf("-----------------------------------------------------------\n");
    
    float totalCost = 0.0;
    for (int i = 0; i < cartSize; i++) {
        printf("%d\t%s\t\t%d\t\t$%.2f\n", i + 1, name[i], cartQuantity[i], cartPrice[i]);
        totalCost += cartQuantity[i] * cartPrice[i];
    }
    printf("\nTotal Cost: $%.2f\n", totalCost);
}

// Function to checkout and update stock
void checkout(char stockName[][50], int stockQuantity[], float stockPrice[], int *stockSize, char cartName[][50], int cartQuantity[], float cartPrice[], int *cartSize) {
    if (*cartSize == 0) {
        printf("Your cart is empty. Nothing to checkout.\n");
        return;
    }

    float totalCost = 0.0;
    for (int i = 0; i < *cartSize; i++) {
        totalCost += cartQuantity[i] * cartPrice[i];
    }

    printf("\nTotal Cost: $%.2f\n", totalCost);

    char confirm;
    printf("Do you want to proceed with the checkout? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        printf("Checkout successful. Thank you for your purchase!\n");

        // Update the stock quantities
        for (int i = 0; i < *cartSize; i++) {
            for (int j = 0; j < *stockSize; j++) {
                if (strcmp(stockName[j], cartName[i]) == 0) {
                    if (stockQuantity[j] >= cartQuantity[i]) { // Ensure stock is sufficient
                        stockQuantity[j] -= cartQuantity[i];
                        break;
                    } else {
                        printf("Not enough stock for %s. Cannot complete purchase.\n", cartName[i]);
                        return;
                    }
                }
            }
        }

        *cartSize = 0;  // Clear the cart

        // Display remaining stock quantities
        printf("\nRemaining Stock:\n");
        displaystock(stockName, stockQuantity, stockPrice, *stockSize);
    } else {
        printf("Checkout cancelled.\n");
    }
}


int main() {
    char stockName[][50] = {"Milk Choc", "Dark Choc", "Mint Chocolate", "White Choc", "Peanut Choc"};
    int stockQuantity[] = {60, 42, 29, 60, 38};
    float stockPrice[] = {12.00, 25.00, 20.00, 15.00, 8.00};
    int stockSize = sizeof(stockQuantity) / sizeof(stockQuantity[0]);

    char (*cartName)[50] = malloc(MAX_CART_ITEMS * sizeof(*cartName));
    int *cartQuantity = malloc(MAX_CART_ITEMS * sizeof(int));
    float *cartPrice = malloc(MAX_CART_ITEMS * sizeof(float));
    int cartSize = 0;

    if (!cartName || !cartQuantity || !cartPrice) {
        printf("Memory allocation failed\n");
        return 1;
    }

    char choice;
    while (1) {
        displayMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                displaystock(stockName, stockQuantity, stockPrice, stockSize);
                break;
            case '2': {
                int index, newquantity;
                printf("Enter the index of the item you want to update: ");
                scanf("%d", &index);
                if (index >= 1 && index <= stockSize) {
                    printf("Enter the new quantity for %s: ", stockName[index - 1]);
                    scanf("%d", &newquantity);
                    updatestock(stockName, stockQuantity, stockSize, index, newquantity);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case '3': {
                int index;
                float newprice;
                printf("Enter the index of the item whose price you want to update: ");
                scanf("%d", &index);
                if (index >= 1 && index <= stockSize) {
                    printf("Enter the new price for %s: ", stockName[index - 1]);
                    scanf("%f", &newprice);
                    changeprice(stockName, stockPrice, stockSize, index, newprice);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case '4': {
                int numItems;
                printf("How many different items do you want to add to the cart? ");
                scanf("%d", &numItems);

                char itemNames[numItems][50];
                int quantities[numItems];
                float prices[numItems];

                for (int i = 0; i < numItems; i++) {
                    int cartIndex;
                    printf("Enter the index of the item you want to add to the cart: ");
                    scanf("%d", &cartIndex);
                    if (cartIndex >= 1 && cartIndex <= stockSize) {
                        printf("Enter the quantity for %s to add to the cart: ", stockName[cartIndex - 1]);
                        scanf("%d", &quantities[i]);
                        strcpy(itemNames[i], stockName[cartIndex - 1]);
                        prices[i] = stockPrice[cartIndex - 1];
                    } else {
                        printf("Invalid index. Skipping this item.\n");
                        i--;
                    }
                }
                addMultipleToCart(cartName, cartQuantity, cartPrice, &cartSize, itemNames, quantities, prices, numItems);
                break;
            }
            case '5':
                viewCart(cartName, cartQuantity, cartPrice, cartSize);
                break;
            case '6': {
                int removeIndex;
                printf("Enter the index of the item you want to remove from the cart: ");
                scanf("%d", &removeIndex);
                removeFromCart(cartName, cartQuantity, cartPrice, &cartSize, removeIndex);
                break;
            }
            case '7':
                checkout(stockName, stockQuantity, stockPrice, &stockSize, cartName, cartQuantity, cartPrice, &cartSize);
                break;
            case '8':
                free(cartName);
                free(cartQuantity);
                free(cartPrice);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}

#include <stdio.h>
#include <string.h>

#define MAX_CART_ITEMS 100

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

// Function to add item to cart
void addToCart(char name[][50], int cartQuantity[], float cartPrice[], int *cartSize, char itemName[], int quantity, float price) {
    for (int i = 0; i < *cartSize; i++) {
        if (strcmp(name[i], itemName) == 0) {
            cartQuantity[i] += quantity;
            printf("Increased quantity of %s to %d.\n", itemName, cartQuantity[i]);
            return;
        }
    }
    if (*cartSize < MAX_CART_ITEMS) {
        strcpy(name[*cartSize], itemName);
        cartQuantity[*cartSize] = quantity;
        cartPrice[*cartSize] = price;
        (*cartSize)++;
        printf("Added %d of %s to the cart.\n", quantity, itemName);
    } else {
        printf("Cart is full. Cannot add more items.\n");
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
void checkout(char name[][50], int quantity[], int *size, int cartQuantity[], float cartPrice[], int *cartSize) {
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
            for (int j = 0; j < *size; j++) {
                if (strcmp(name[j], name[i]) == 0) {
                    quantity[j] -= cartQuantity[i];
                    break;
                }
            }
        }

        *cartSize = 0;  // Clear the cart
    } else {
        printf("Checkout cancelled.\n");
    }
}

int main() {
    char name[][50] = {"Milk Choc", "Dark Choc", "Mint Chocolate", "White Choc", "Peanut Choc"};
    int quantity[] = {60, 42, 29, 60, 38};
    float price[] = {12.00, 25.00, 20.00, 15.00, 8.00};
    int size = sizeof(quantity) / sizeof(quantity[0]);

    char cartName[MAX_CART_ITEMS][50];
    int cartQuantity[MAX_CART_ITEMS];
    float cartPrice[MAX_CART_ITEMS];
    int cartSize = 0;

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

    // Display updated stock
    printf("\nUpdated Stock:\n");
    displaystock(name, quantity, price, size);

    // Adding items to the cart
    int cartIndex, cartQuantityInput;
    printf("\nEnter the index of the item you want to add to the cart: ");
    scanf("%d", &cartIndex);
    if (cartIndex >= 1 && cartIndex <= size) {
        printf("Enter the quantity for %s to add to the cart: ", name[cartIndex - 1]);
        scanf("%d", &cartQuantityInput);
        addToCart(cartName, cartQuantity, cartPrice, &cartSize, name[cartIndex - 1], cartQuantityInput, price[cartIndex - 1]);
    } else {
        printf("Invalid index.\n");
    }

    // View cart contents
    viewCart(cartName, cartQuantity, cartPrice, cartSize);

    // Ask user if they want to remove an item
    char removeChoice;
    printf("\nDo you want to remove an item from the cart? (y/n): ");
    scanf(" %c", &removeChoice);
    if (removeChoice == 'y' || removeChoice == 'Y') {
        int removeIndex;
        printf("Enter the index of the item you want to remove from the cart: ");
        scanf("%d", &removeIndex);
        removeFromCart(cartName, cartQuantity, cartPrice, &cartSize, removeIndex);
    }

    // Display cart contents after removal
    viewCart(cartName, cartQuantity, cartPrice, cartSize);

    // Proceed to checkout
    printf("\nDo you want to proceed to checkout? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        checkout(name, quantity, &size, cartQuantity, cartPrice, &cartSize);
    } else {
        printf("Checkout cancelled.\n");
    }

    // Display final stock after checkout
    printf("\nFinal Stock:\n");
    displaystock(name, quantity, price, size);

    return 0;
}


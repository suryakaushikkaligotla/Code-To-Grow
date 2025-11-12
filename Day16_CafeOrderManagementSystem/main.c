#include <stdio.h>

int main() {

    int itemprices[5] = {50, 30, 80, 120, 60};
    char itemnames[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int itemsold[5] = {0, 0, 0, 0, 0};
    int customers;
    int numofitems;
    int itemno;
    int quantity;
    int totalrevenue = 0;
    int totalitemssold = 0;
    int mostordered = 0;
    int leastordered = 0;

    printf("----- Cafe Order Management System -----\n");
    printf("This is our Menu - \n");
    printf("Item No.\tItem Name\tPrice (₹)\n");

    for (int i = 0; i < 5; i++) {
        printf("%d\t\t%-10s\t₹%d\n", i + 1, itemnames[i], itemprices[i]);
    }

    printf("\nPlease enter the total number of customers (max 10): ");
    scanf("%d", &customers);

    if (customers < 1 || customers > 10) {
        printf("Invalid number of customers! Please restart the program.\n");
        return 0;
    }

    for (int x = 0; x < customers; x++) {
        int customertotal = 0;

        printf("\n--- Customer %d ---\n", x + 1);
        printf("Please enter the number of items: ");
        scanf("%d", &numofitems);

        printf("Enter item number and quantity (e.g., 1 2):\n");

        for (int y = 0; y < numofitems; y++) {
            scanf("%d %d", &itemno, &quantity);

            if (itemno < 1 || itemno > 5 || quantity <= 0) {
                printf("Invalid item number or quantity! This entry will be skipped.\n");
                continue;
            }

            customertotal += itemprices[itemno - 1] * quantity;
            itemsold[itemno - 1] += quantity;
            totalitemssold += quantity;
        }

        totalrevenue += customertotal;
        printf("Total Bill for Customer %d: ₹%d\n", x + 1, customertotal);
    }

    for (int i = 1; i < 5; i++) {
        if (itemsold[i] > itemsold[mostordered])
            mostordered = i;
        if (itemsold[i] < itemsold[leastordered])
            leastordered = i;
    }

    printf("\n----- Cafe Summary -----\n");
    printf("Total Revenue: ₹%d\n", totalrevenue);
    printf("Total Items Sold: %d\n", totalitemssold);
    printf("Most Ordered Item: %s\n", itemnames[mostordered]);
    printf("Least Ordered Item: %s\n", itemnames[leastordered]);
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    return 0;
}


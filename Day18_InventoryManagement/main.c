/*Name: Kaushik Kaligotla
Register Number: AP25110090168
Day 18 - Inventory Management System*/

#include <stdio.h>

int main() {
    int productid[10];
    char name[10][50];
    int quantity[10];
    float price[10];
    int n;
    int choice;
    int i;

    float totalvalue = 0;
    float highestvalue;
    float lowestvalue;
    int highest = 0;
    int lowest = 0;
    int searchid;
    int found;

    printf("Enter number of products (max 10): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for product %d:\n", i + 1);
        printf("Product ID: ");
        scanf("%d", &productid[i]);

        printf("Product Name: ");
        scanf("%s", name[i]);

        printf("Quantity: ");
        scanf("%d", &quantity[i]);

        printf("Price per item: ");
        scanf("%f", &price[i]);
    }

    do {
        printf("\n===== Inventory Management Menu =====\n");
        printf("1. Display all products\n");
        printf("2. Show total inventory value\n");
        printf("3. Show highest & lowest valued products\n");
        printf("4. Search product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n--- Product List ---\n");
            for (i = 0; i < n; i++) {
                printf("ID: %d | Name: %s | Qty: %d | Price: %.2f | Value: %.2f\n",
                    productid[i], name[i], quantity[i], price[i], quantity[i] * price[i]);
            }
        }

        else if (choice == 2) {
            totalvalue = 0;
            for (i = 0; i < n; i++) {
                totalvalue += quantity[i] * price[i];
            }
            printf("\nTotal Inventory Value = %.2f\n", totalvalue);
        }

        else if (choice == 3) {
            highestvalue = quantity[0] * price[0];
            lowestvalue = quantity[0] * price[0];

            for (i = 1; i < n; i++) {
                float value = quantity[i] * price[i];

                if (value > highestvalue) {
                    highestvalue = value;
                    highest = i;
                }

                if (value < lowestvalue) {
                    lowestvalue = value;
                    lowest = i;
                }
            }

            printf("\n--- Highest Valued Product ---\n");
            printf("ID: %d | Name: %s | Value: %.2f\n",
                   productid[highest], name[highest], highestvalue);

            printf("\n--- Lowest Valued Product ---\n");
            printf("ID: %d | Name: %s | Value: %.2f\n",
                   productid[lowest], name[lowest], lowestvalue);
        }

        else if (choice == 4) {
            printf("Enter Product ID to search: ");
            scanf("%d", &searchid);

            found = 0;

            for (i = 0; i < n; i++) {
                if (productid[i] == searchid) {
                    printf("\nProduct Found:\n");
                    printf("ID: %d | Name: %s | Qty: %d | Price: %.2f | Value: %.2f\n",
                           productid[i], name[i], quantity[i], price[i],
                           quantity[i] * price[i]);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nProduct with ID %d not found.\n", searchid);
            }
        }

        else if (choice == 5) {
            printf("\nExiting program...\n");
        }

        else {
            printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

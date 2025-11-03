#include <stdio.h>

int main() {
    int TotalCustomers;
    float CanteenAmount = 0.0;
    int NoOfCustomers = 1; 
    int NoOfItems;
    float TotalBill;
    int ItemCode;
    int Quantity;
    float price = 0;
    float ItemTotal = 0;

    printf("Total Number of Customers: ");
    scanf("%d", &TotalCustomers);

   
    while (NoOfCustomers <= TotalCustomers) {
        TotalBill = 0;
        printf("Customer %d\n", NoOfCustomers);
        printf("----------\n");

        printf("---Menu Card---\n");
        printf(" 1. Sandwich - ₹80\n");
        printf(" 2. Burger   - ₹120\n");
        printf(" 3. Pizza    - ₹150\n");
        printf(" 4. Coffee   - ₹60\n");
        printf(" 5. Juice    - ₹50\n");

        printf("Enter the number of items to place an order: ");
        scanf("%d", &NoOfItems);

        int ItemCount = 1;
        
        while (ItemCount <= NoOfItems) {
            printf("Please enter the required item code (1-5): ");
            scanf("%d", &ItemCode);

            printf("Enter the quantity of the item: ");
            scanf("%d", &Quantity);

            if (ItemCode == 1) {
                price = 80;
            } else if (ItemCode == 2) {
                price = 120;
            } else if (ItemCode == 3) {
                price = 150;
            } else if (ItemCode == 4) {
                price = 60;
            } else if (ItemCode == 5) {
                price = 50;
            } else {
                printf("Invalid code! Item ignored.\n");
                continue; 
            }

            ItemTotal = price * Quantity;
            TotalBill += ItemTotal; 

            printf("Item Total = ₹%.2f\n", ItemTotal);
            ItemCount++;
        }

        if (TotalBill > 500) {
            float Discount = TotalBill * 0.10;
            TotalBill -= Discount;
            printf("Applied a discount of 10%%, ₹%.2f\n", Discount);
        }

       
        CanteenAmount += TotalBill;

        printf("Total bill for Customer %d = ₹%.2f\n", NoOfCustomers, TotalBill);

        NoOfCustomers++; 
    }

    
    printf("--------------------------\n");
    printf("Canteen Bill Summary\n");
    printf("--------------------------\n");
    printf("Total number of customers: %d\n", TotalCustomers);
    printf("Total amount collected: ₹%.2f\n", CanteenAmount);

    return 0;
}

#include <stdio.h>

int main() {
    int choice;
    int transactions = 0;
    float balance = 10000.0;
    float amount;
    int MaxTransactions = 5;

    printf("-------Mini ATM Simulator-------\n");
    printf("Initial Balance: ₹%.2f\n", balance);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Your current balance is: ₹%.2f\n", balance);
            transactions++;
        } 
        else if (choice == 2) {
            printf("Enter amount to deposit: ₹");
            scanf("%f", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Successfully deposited ₹%.2f\n", amount);
                printf("Updated Balance: ₹%.2f\n", balance);
                transactions++;
            } else {
                printf("Invalid deposit amount!\n");
            }
        } 
        else if (choice == 3) {
            printf("Enter amount to withdraw: ₹");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid withdrawal amount!\n");
            } 
            else if (amount > balance - 500) { 
                printf("Insufficient balance! Minimum ₹500 must remain.\n");
            } 
            else {
                balance -= amount;
                printf("Successfully withdrew ₹%.2f\n", amount);
                printf("Updated Balance: ₹%.2f\n", balance);
                transactions++;
            }
        } 
        else if (choice == 4) {
            printf("Exiting... Thank you for using Mini ATM!\n");
            break;
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }

        if (transactions >= MaxTransactions) {
            printf("\nMaximum transactions limit reached!\n");
            break;
        }

    } while (choice != 4);

    printf("\n-------SESSION SUMMARY-------\n");
    printf("Total Transactions Done: %d\n", transactions);
    printf("Final Balance: ₹%.2f\n", balance);
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    return 0;
}

#include <stdio.h>

int main() {
// Declaring values//
    int choice;
    int transactions = 0;
    float balance = 10000.0;
    float amount;
    int MaxTransactions = 5;
//The standard interface for the simulator and based on the choices the else if commands come in place//
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
// To check balance
        if (choice == 1) {
            printf("Your current balance is: ₹%.2f\n", balance);
            transactions++;
            
            //To deposit money
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
        // To Withdraw money//
        else if (choice == 3) {
            printf("Enter amount to withdraw: ₹");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid withdrawal amount!\n");

                //For minimum account balance
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

        //Exiting ATM
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
// Summary of the session//
    printf("\n-------SESSION SUMMARY-------\n");
    printf("Total Transactions Done: %d\n", transactions);
    printf("Final Balance: ₹%.2f\n", balance);
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    return 0;
}

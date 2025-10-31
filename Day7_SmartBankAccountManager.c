#include <stdio.h>

int main() {
    int balance;
    int deposit;
    int withdraw;
    int choice;
    int bonus;

    balance = 10000;

    do {
        printf("------- Smart Bank Account Manager -------\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter amount to deposit: ");
            scanf("%d", &deposit);

            balance = balance + deposit;

            if (deposit > 25000) {
                bonus = deposit * 0.01;
                balance = balance + bonus;
                printf("Bonus of ₹ %d added!\n", bonus);
            }

            printf("Service charge of ₹5 applied.\n");
            balance = balance - 5;
            printf("Your updated balance is ₹ %d\n", balance);
        }

        else if (choice == 2) {
            printf("\nEnter amount to withdraw: ");
            scanf("%d", &withdraw);

            if (withdraw > balance) {
                printf("You have Insufficient balance!\n");
            } else {
                balance = balance - withdraw;
                printf("A service charge of ₹5 has been applied.\n");
                balance = balance - 5;
                printf("Your updated balance is ₹ %d\n", balance);
            }
        }

        else if (choice == 3) {
            printf("\nCurrent balance: ₹ %d\n", balance);
        }

        else if (choice != 4) {
            printf("\nInvalid choice. Please try again.\n\n");
        }

    } while (choice != 4);

    printf("Thank you for banking with us!\n");
    return 0;
}
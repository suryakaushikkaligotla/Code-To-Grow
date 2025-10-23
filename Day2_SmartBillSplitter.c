
#include <stdio.h>

int main() {
    float meal_cost, tax, tip, total_bill;
    float friend1, friend2, friend3;

    //Taking User Input for meal cost//
    printf("Enter meal cost: ");
    scanf("%f", &meal_cost);

    //Calculating Tax and Tip//
    tax = 0.05 * meal_cost;   
    tip = 0.10 * meal_cost;   

    //Calculating total bill with meal cost, tax and tip//
    total_bill = meal_cost + tax + tip;

    //Objective is to split the bill in 3 ways but with a few challenges//

    // The bill should be split among 3 people//

    //Because a friend forgot their wallet, we need to pay half of their share as well as pay for our share of the bill//

    //Friend 2 pays half of friend 3's share as well//
    
    friend1 = (total_bill / 3) + ((total_bill / 3) / 2);
    friend2 = friend1;
    friend3 = 0;

    // Display results
    printf("\nTotal bill: %.2f\n", total_bill);
    printf("Each person should pay the amount:\n");
    printf("Amount paid by Friend 1: %.2f\n", friend1);
    printf("Amount paid by Friend 2: %.2f\n", friend2);
    printf("Amount paid by Friend 3: %.2f\n", friend3);

    return 0;
}
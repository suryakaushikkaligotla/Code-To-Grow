// For today's challenge, we need to make a smart fare calculator for the SRM University shuttle system.// //We need to calculate the fare based on the number of passengers, age, distance and time of travel, that is determining if it is in peak time or non peak time// //The standard bus fare is ₹10 per kilometre, and children under the age of 12 get 50% off, senior citizens above the age of 60 get 30% off// //Peak hour charge applies between 8-10 AM and 5-8 PM, and the charge is 20% extra// //The minimum fare should be ₹20//

#include <stdio.h>

int main() {
    int totalpassengers;
    int i;
    char name[50];
    int age;
    float distance;
    int time;
    float basefare, finalfare;
    float totalrevenue = 0;
    float highestfare = 0;
    float lowestfare = 99999; // Fixed semicolon

    // Standard declaring variables till here

    printf("---------- SRM Smart Bus Fare Calculator ----------\n");
    printf("Enter number of passengers: ");
    scanf("%d", &totalpassengers);

    for (i = 1; i <= totalpassengers; i++) {
        printf("\n------ Passenger %d ------\n", i);

        printf("Please Enter name: ");
        scanf("%s", name);

        printf("Please Enter age: ");
        scanf("%d", &age);

        printf("Please Enter distance (in km): ");
        scanf("%f", &distance);

        printf("Please Enter travel time (24-hour format): ");
        scanf("%d", &time);

        // Calculating base fare
        basefare = distance * 10;
        finalfare = basefare;

        // Applying discounts
        if (age < 12) {
            finalfare = basefare * 0.5;
            printf("Passenger: %s - Base Fare: ₹%.2f - Child Discount Applied", name, basefare);
        } 
        else if (age >= 60) {
            finalfare = basefare * 0.7;
            printf("Passenger: %s - Base Fare: ₹%.2f - Senior Citizen Discount Applied", name, basefare);
        } 
        else {
            printf("Passenger: %s - Base Fare: ₹%.2f", name, basefare);
        }

        // Checking for peak hours
        if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) {
            finalfare = finalfare * 1.2;
            printf(" | Peak Hour Surcharge Applied");
        }

        // Applying minimum fare rule
        if (finalfare < 20) {
            finalfare = 20;
        }

        printf(" | Final Fare: ₹%.2f\n", finalfare);

        // Updating summary data
        totalrevenue += finalfare;

        if (finalfare > highestfare)
            highestfare = finalfare;

        if (finalfare < lowestfare)
            lowestfare = finalfare;
    }

    // Printing summary
    printf("\n---------- Fare Summary ----------\n");
    printf("Total Passengers: %d\n", totalpassengers);
    printf("Total Revenue Collected: ₹%.2f\n", totalrevenue);
    printf("Highest Fare: ₹%.2f\n", highestfare);
    printf("Lowest Fare: ₹%.2f\n", lowestfare);
    printf("===================================\n");

    return 0;
}

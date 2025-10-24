#include <stdio.h>

int main() {
    int units;
    float totalBill = 0.0;
    float meterCharge = 50.0;

    // total units consumed input//
    printf("total units consumed: ");
    scanf("%d", &units);

    // Calculate total bill//
    if (units <= 100) {
        totalBill = units * 3.0;
    }
    else if (units <= 200) {
        totalBill = units * 4.5;
    }
    else if (units <= 300) {
        totalBill = units * 6.0;
    }
    else {
        totalBill = units * 8.0;
    }

    totalBill += meterCharge;

//Display output//
    printf("\nElectricity Bill :\n");
    printf("Units Consumed: %d\n", units);
    printf("Total Bill including fixed charge): ₹%.2f\n", totalBill);

    return 0;
}
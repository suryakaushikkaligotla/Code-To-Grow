#include <stdio.h>

int main() {
    float basic_salary, hra_percent, da_percent, tax_percent;
    float hra, da, tax, gross_salary;
    int is_above_50000;
    printf("Enter basic salary:");
    scanf("%f", &basic_salary);

    printf("Enter HRA%%: ");
    scanf("%f", &hra_percent);

    printf("Enter DA%%: ");
    scanf("%f", &da_percent);

    printf("Enter Tax%%: ");
    scanf("%f", &tax_percent);

    hra =basic_salary*(hra_percent/100);

    da =basic_salary*(da_percent / 100);

    tax =basic_salary*(tax_percent/100);

    gross_salary = basic_salary + hra + da - tax;

    is_above_50000 =gross_salary>50000;

    printf("\nHRA = %.2f", hra);
    printf("\nDA = %.2f", da);
    printf("\nTAX = %.2f", tax);
    printf("\nGross Salary = %.2f", gross_salary);
    printf("\nIs Gross Salary above 50000? %d\n", is_above_50000);

    return 0;
}

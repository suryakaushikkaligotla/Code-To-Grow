#include <stdio.h>

int main() {
    char name[50];
    char regno[20];
    char section[10];
    int salary[10];
    int n;
    int choice;
    int i;
    int total;
    int highest;
    int lowest; 
    int aboveavg;
    int belowavg;
    float avg;
    int temp;

    printf("Enter Student Name: ");
    scanf(" %s", name);
    printf("Enter Registration Number: ");
    scanf(" %s", regno);
    printf("Enter Section: ");
    scanf(" %s", section);

    printf("Enter number of employees (max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid number of employees. Exiting program.\n");
        return 0;
    }

    for(i = 0; i < n; i++) {
        printf("Enter salary of employee %d: ", i + 1);
        scanf("%d", &salary[i]);
    }
 
    do {
        printf("\n========== Menu ==========\n");
        printf("1. Display All Salaries\n");
        printf("2. Display Total and Average Salary\n");
        printf("3. Display Highest and Lowest Salary\n");
        printf("4. Count Above/Below Average\n");
        printf("5. Display Sorted Salaries (Ascending)\n");
        printf("6. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\nSubmitted by: %s | Reg No: %s | Section: %s\n", name, regno, section);
        printf("Challenge Day 17 – Code2Grow Program\n\n");

        if (choice == 1) {
            printf("Salaries: ");
            for(i = 0; i < n; i++) {
                printf("%d ", salary[i]);
            }
            printf("\n");
        }
        else if (choice == 2) {
            total = 0;
            for(i = 0; i < n; i++)
                total += salary[i];
            avg = (float)total / n;
            printf("Total Salary: %d\nAverage Salary: %.2f\n", total, avg);
        }
        else if (choice == 3) {
            highest = lowest = salary[0];
            for(i = 1; i < n; i++) {
                if (salary[i] > highest) highest = salary[i];
                if (salary[i] < lowest) lowest = salary[i];
            }
            printf("Highest Salary: %d\nLowest Salary: %d\n", highest, lowest);
        }
        else if (choice == 4) {
            total = 0;
            for(i = 0; i < n; i++)
                total += salary[i];
            avg = (float)total / n;

            aboveavg = belowavg = 0;
            for(i = 0; i < n; i++) {
                if (salary[i] > avg) aboveavg++;
                else if (salary[i] < avg) belowavg++;
            }
            printf("Employees Above Average: %d\nEmployees Below Average: %d\n", aboveavg, belowavg);
        }
        else if (choice == 5) {
            for(int pass = 0; pass < n - 1; pass++) {
                for(i = 0; i < n - pass - 1; i++) {
                    if(salary[i] > salary[i + 1]) {
                        temp = salary[i];
                        salary[i] = salary[i + 1];
                        salary[i + 1] = temp;
                    }
                }
            }
            printf("Sorted Salaries (Ascending): ");
            for(i = 0; i < n; i++) {
                printf("%d ", salary[i]);
            }
            printf("\n");
        }
        else if (choice == 6) {
            printf("Exit!\n");
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

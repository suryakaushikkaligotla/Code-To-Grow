#include <stdio.h>

int main() {
    float attendance;
    float totalPercentage, conditionalTotalPercentage;
    int subject1, subject2, subject3, subject4, subject5;

    //Inputing marks//
    printf("Enter the marks obtained in each subject: ");
    scanf("%d %d %d %d %d", &subject1, &subject2, &subject3, &subject4, &subject5);

    //Inputing attendance//
    printf("Enter attendance percentage: ");
    scanf("%f", &attendance);

    //Calculating percentage of subjects//
    totalPercentage = (subject1 + subject2 + subject3 + subject4 + subject5) / 5.0;
    conditionalTotalPercentage = totalPercentage + 5;

    printf("\nTotal Percentage: %.2f%%\n", totalPercentage);

    //Checking Attendance percentage first//
    if (attendance < 75) {
        printf("Final Grade: F\n");
        printf("Remarks: Fail (Low Attendance)\n");
        printf("You have failed because your attendance was under 75%%.\n");
    } 
    else {
        //Grace marks//
        if (totalPercentage >= 45 && totalPercentage < 50 && attendance >= 90) {
            totalPercentage = conditionalTotalPercentage;
            if (totalPercentage > 100)
                totalPercentage = 100;
            printf("Grace marks applied due to high attendance!\n");
        }
        if (totalPercentage >= 90) {
            printf("Final Grade: A\n");
            printf("Remarks: Excellent!\n");
        } 
        else {
            if (totalPercentage >= 80) {
                printf("Final Grade: B\n");
                printf("Remarks: Very Good!\n");
            } 
            else {
                if (totalPercentage >= 70) {
                    printf("Final Grade: C\n");
                    printf("Remarks: Good!\n");
                } 
                else {
                    if (totalPercentage >= 60) {
                        printf("Final Grade: D\n");
                        printf("Remarks: Average\n");
                    } 
                    else {
                        if (totalPercentage >= 50) {
                            printf("Final Grade: E\n");
                            printf("Remarks: Pass\n");
                        } 
                        else {
                            printf("Final Grade: F\n");
                            printf("Remarks: Fail\n");
                        }
                    }
                }
            }
        }

        
    }

    return 0;
}
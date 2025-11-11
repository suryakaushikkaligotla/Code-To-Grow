#include <stdio.h>

int main() {
    int noofstudents;
    int marks[10];
    int eachmarks;
    int highestm;
    int lowestm;
    int totalpassed = 0;
    int totalfailed = 0;
    int gradeAplus = 0;
    int gradeA = 0;
    int gradeB = 0;
    int gradeC = 0;
    int gradeD = 0;
    int gradeF = 0;
    int mks;
    float sum = 0;
    float average;

    printf("------ Student Performance Analyzer -----\n");
    printf("Please enter the total number of students (The maximum is 10): ");
    scanf("%d", &noofstudents);

    // Validate input
    if (noofstudents <= 0 || noofstudents > 10) {
        printf("Invalid number of students! Please enter a value between 1 and 10.\n");
        return 0;
    }

    // Input marks
    printf("Please enter the marks for each student:\n");
    for (mks = 0; mks < noofstudents; mks++) {
        printf("Student %d - ", mks + 1);
        scanf("%d", &eachmarks);

        while (eachmarks < 0 || eachmarks > 100) {
            printf("Invalid marks! Enter again (0–100): ");
            scanf("%d", &eachmarks);
        }

        marks[mks] = eachmarks;
        sum += marks[mks];
    }

    // Initialize highest and lowest
    highestm = marks[0];
    lowestm = marks[0];

    // Process all students for grades and statistics
    for (mks = 0; mks < noofstudents; mks++) {
        if (marks[mks] > highestm)
            highestm = marks[mks];
        if (marks[mks] < lowestm)
            lowestm = marks[mks];

        if (marks[mks] >= 90) {
            gradeAplus++;
            totalpassed++;
        } else if (marks[mks] >= 80) {
            gradeA++;
            totalpassed++;
        } else if (marks[mks] >= 70) {
            gradeB++;
            totalpassed++;
        } else if (marks[mks] >= 60) {
            gradeC++;
            totalpassed++;
        } else if (marks[mks] >= 50) {
            gradeD++;
            totalpassed++;
        } else {
            gradeF++;
            totalfailed++;
        }
    }

    // Compute average
    average = sum / noofstudents;

    // Output results
    printf("\n------- Total Summary ------\n");
    printf("The Average marks are   : %.2f\n", average);
    printf("The Highest Marks are   : %d\n", highestm);
    printf("The Lowest Marks are    : %d\n", lowestm);
    printf("Total Passed Students   : %d\n", totalpassed);
    printf("Total Failed Students   : %d\n", totalfailed);
    printf("Grade Distribution:\n");
    printf("A+ Students  : %d\n", gradeAplus);
    printf("A  Students  : %d\n", gradeA);
    printf("B  Students  : %d\n", gradeB);
    printf("C  Students  : %d\n", gradeC);
    printf("D  Students  : %d\n", gradeD);
    printf("Fail Students: %d\n", gradeF);
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

    return 0;
}

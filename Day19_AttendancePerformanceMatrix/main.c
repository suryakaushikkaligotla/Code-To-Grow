#include <stdio.h>

int main() {
    int attendance[5][5];
    int marks[5][5];
    char names[5][20];

    int i, j, choice;

    int totalAttendance[5] = {0};
    int totalAbsence[5] = {0};
    int totalMarks[5] = {0};
    float avgMarks[5] = {0};

    int highestAttendance = -1;
    int lowestAttendance = 999;
    int highestAttendanceIndex = 0;
    int lowestAttendanceIndex = 0;

    int highestMarks = -1;
    int lowestMarks = 999;
    int topperIndex = 0;
    int lowIndex = 0;

    printf("Enter names of 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("\nEnter Attendance (1 for Present, 0 for Absent), of 5 Subjects each-\n");
    for (i = 0; i < 5; i++) {
        printf("Student %s:\n", names[i]);
        for (j = 0; j < 5; j++) {
            scanf("%d", &attendance[i][j]);
        }
    }

    printf("\nEnter Marks (0–100)-\n");
    for (i = 0; i < 5; i++) {
        printf("Student %s:\n", names[i]);
        for (j = 0; j < 5; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        totalAttendance[i] = 0;
        totalAbsence[i] = 0;
        totalMarks[i] = 0;

        for (j = 0; j < 5; j++) {
            if (attendance[i][j] == 1)
                totalAttendance[i]++;
            else
                totalAbsence[i]++;

            totalMarks[i] += marks[i][j];
        }

        avgMarks[i] = totalMarks[i] / 5.0;

        if (totalAttendance[i] > highestAttendance) {
            highestAttendance = totalAttendance[i];
            highestAttendanceIndex = i;
        }

        if (totalAttendance[i] < lowestAttendance) {
            lowestAttendance = totalAttendance[i];
            lowestAttendanceIndex = i;
        }

        if (totalMarks[i] > highestMarks) {
            highestMarks = totalMarks[i];
            topperIndex = i;
        }

        if (totalMarks[i] < lowestMarks) {
            lowestMarks = totalMarks[i];
            lowIndex = i;
        }
    }

    do {
        printf("\n========= MENU =========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n--- Attendance Matrix ---\n");
            for (i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++) {
                    printf("%d ", attendance[i][j]);
                }
                printf("\n");
            }
        }

        else if (choice == 2) {
            printf("\n--- Marks Matrix ---\n");
            for (i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++) {
                    printf("%d ", marks[i][j]);
                }
                printf("\n");
            }
        }

        else if (choice == 3) {
            printf("\n--- Attendance Report ---\n");
            for (i = 0; i < 5; i++) {
                printf("%s → Present: %d, Absent: %d\n",
                       names[i], totalAttendance[i], totalAbsence[i]);
            }
            printf("\nHighest Attendance: %s (%d)\n",
                   names[highestAttendanceIndex], highestAttendance);
            printf("Lowest Attendance: %s (%d)\n",
                   names[lowestAttendanceIndex], lowestAttendance);
        }

        else if (choice == 4) {
            printf("\n--- Performance Report ---\n");
            for (i = 0; i < 5; i++) {
                printf("%s → Total: %d, Average: %.2f\n",
                       names[i], totalMarks[i], avgMarks[i]);
            }
            printf("\nClass Topper: %s (%d marks)\n",
                   names[topperIndex], highestMarks);
            printf("Lowest Performer: %s (%d marks)\n",
                   names[lowIndex], lowestMarks);
        }

        else if (choice == 5) {
            printf("\n--- Grade Report ---\n");
            for (i = 0; i < 5; i++) {
                if (avgMarks[i] >= 90)
                    printf("%s → Average: %.2f, Grade: A+\n", names[i], avgMarks[i]);
                else if (avgMarks[i] >= 80)
                    printf("%s → Average: %.2f, Grade: A\n", names[i], avgMarks[i]);
                else if (avgMarks[i] >= 70)
                    printf("%s → Average: %.2f, Grade: B\n", names[i], avgMarks[i]);
                else if (avgMarks[i] >= 60)
                    printf("%s → Average: %.2f, Grade: C\n", names[i], avgMarks[i]);
                else if (avgMarks[i] >= 50)
                    printf("%s → Average: %.2f, Grade: D\n", names[i], avgMarks[i]);
                else
                    printf("%s → Average: %.2f, Grade: F\n", names[i], avgMarks[i]);
            }
        }

        else if (choice == 6) {
            printf("Exit\n");
        }

        else {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

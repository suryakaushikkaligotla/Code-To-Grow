#include <stdio.h>

void showSeatMatrix(int seats[8][3]) {
    printf("\n===== SEAT MATRIX =====\n");
    printf("       A B C\n");
    for (int i = 0; i < 8; i++) {
        printf("Row %d:  ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%d ", seats[i][j]);
        }
        printf("\n");
    }
}

int main() {

    char city[5][20] = {
        "Hyderabad",
        "Guntur",
        "Vijayawada",
        "Bengaluru",
        "Vizag"
    };

    char busstop[5][30] = {
        "KPHB Bus Stop",
        "Guntur RTC Complex",
        "Benz Circle Bus Stop",
        "Majestic Bus Stand",
        "Gajuwaka Bus Stop"
    };

    char subroute[5][5][30] = {
        {"---", "Mangalagiri", "Ibrahimpatnam", "Anantapur", "Rajahmundry"},
        {"LB Nagar", "---", "Tenali", "Nellore", "Ongole"},
        {"Nalgonda", "Mangalagiri", "---", "Tirupati", "Eluru"},
        {"Kurnool", "Kadapa", "Madanapalle", "---", "Tumkur"},
        {"Tuni", "Ongole", "Vijayawada", "Tirupati", "---"}
    };

    int distance[5][5] = {
        {0, 270, 275, 570, 620},
        {270, 0, 30, 520, 520},
        {275, 30, 0, 480, 350},
        {570, 520, 480, 0, 800},
        {620, 520, 350, 800, 0}
    };

    int seats[8][3] = {
        {0,0,0},{0,1,0},{1,0,0},{0,0,1},
        {0,0,0},{1,1,0},{0,0,0},{0,1,1}
    };

    int dep, des, tickets;
    int row, col;
    char colChar;

    printf("-------WAGWAN BUS BOOKING SYSTEM-------\n");
    printf("Please select your place of departure-\n");

    for (int i = 0; i < 5; i++)
        printf("%d. %s (%s)\n", i + 1, city[i], busstop[i]);

    printf("\nEnter Departure City (1-5)- ");
    scanf("%d", &dep);
    dep--;

    printf("Enter Destination City (1-5)- ");
    scanf("%d", &des);
    des--;

    if (dep == des) {
        printf("\nDeparture and destination cannot be the same!\n");
        return 0;
    }

    printf("\n-------TRAVEL DETAILS-------\n");
    printf("From: %s (%s)\n", city[dep], busstop[dep]);
    printf("To:   %s (%s)\n", city[des], busstop[des]);
    printf("Sub-route Stop: %s\n", subroute[dep][des]);

    printf("Full Route: %s → %s → %s\n",
           city[dep], subroute[dep][des], city[des]);

    int d = distance[dep][des];
    int baseFare = d * 1;
    int gst = baseFare * 5 / 100;
    int totalFare = baseFare + gst;

    printf("\nDistance: %d km\n", d);
    printf("Base Fare: ₹%d\n", baseFare);
    printf("GST (5%%): ₹%d\n", gst);
    printf("Total Fare: ₹%d\n", totalFare);

    printf("\nEnter number of tickets to book: ");
    scanf("%d", &tickets);

    showSeatMatrix(seats);

    printf("\n===== SELECT YOUR SEATS =====\n");

    for (int t = 1; t <= tickets; t++) {

        printf("\nTicket %d:\n", t);

        printf("Please enter Row (1-8): ");
        scanf("%d", &row);
        row--;

        printf("Please enter Column (A/B/C): ");
        scanf(" %c", &colChar);

        if (colChar == 'A' || colChar == 'a') col = 0;
        else if (colChar == 'B' || colChar == 'b') col = 1;
        else col = 2;

        if (seats[row][col] == 1) {
            printf("Seat already booked! Please try another seat.\n");
            t--;
            continue;
        }

        seats[row][col] = 1;

        printf("Seat %d%c has been successfully booked!\n", row + 1, colChar);
    }

    showSeatMatrix(seats);

    printf("\n--------BOOKING RECEIPT--------\n");
    printf("Route: %s → %s → %s\n", city[dep], subroute[dep][des], city[des]);
    printf("Tickets Booked: %d\n", tickets);
    printf("Cost per Ticket: ₹%d\n", totalFare);
    printf("Total Amount: ₹%d\n", totalFare * tickets);
    printf("Thank you for booking using Wagwan!\n");

    return 0;
}

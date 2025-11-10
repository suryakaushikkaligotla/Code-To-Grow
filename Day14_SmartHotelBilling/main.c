#include <stdio.h>


int main() {
   int totalcustomers;
   int customercount = 1;
   int totalroomsbooked = 0;
   int days;
   int roomtype;
   float totalrevenue = 0;
   float highestbill = 0;
   float lowestbill = 0;
   float rate = 0;
   float basefare = 0;
   float services = 0;
   float subtotal = 0;
   float discount = 0;
   float gst = 0;
   float finalbill = 0;
   char name[50];
   char breakfast;
   char wifi;
   char gym;


   printf("------ Smart Hotel Room Booking Service ------\n");
   printf("Please enter the total number of customers: ");
   scanf("%d", &totalcustomers);


   while (customercount <= totalcustomers) {


       printf("\n--- Customer %d ---\n", customercount);
       printf("Please enter name: ");
       scanf("%s", name);


       printf("Enter room type (1 for Deluxe, 2 for Super Deluxe, 3 for Suite): ");
       scanf("%d", &roomtype);


       if (roomtype == 1)
           rate = 2500;
       else if (roomtype == 2)
           rate = 4000;
       else if (roomtype == 3)
           rate = 6000;
       else {
           printf("Invalid room type. Default room will be Deluxe.\n");
           rate = 2500;
       }


       printf("Please enter the number of days of your stay: ");
       scanf("%d", &days);


       basefare = rate * days;


       printf("Do you want Breakfast with your stay? (Y/N): ");
       scanf(" %c", &breakfast);


       printf("Do you want Wi-Fi with your stay? (Y/N): ");
       scanf(" %c", &wifi);


       printf("Do you want Gym Access with your stay? (Y/N): ");
       scanf(" %c", &gym);


       services = 0;
       if (breakfast == 'Y' || breakfast == 'y')
           services += 300 * days;
       if (wifi == 'Y' || wifi == 'y')
           services += 100 * days;
       if (gym == 'Y' || gym == 'y')
           services += 200 * days;


       subtotal = basefare + services;


       if (subtotal > 10000)
           discount = subtotal * 0.10;
       else
           discount = 0;


       subtotal -= discount;


       gst = subtotal * 0.12;
       finalbill = subtotal + gst;


       printf("\n===== Bill for %s =====\n", name);
       printf("Base Fare: ₹%.0f\n", basefare);
       printf("Additional Services: ₹%.0f\n", services);
       printf("Subtotal: ₹%.0f\n", basefare + services);
       printf("Discount (10%%): ₹%.0f\n", discount);
       printf("GST (12%%): ₹%.0f\n", gst);
       printf("Final Bill: ₹%.0f\n", finalbill);


       totalroomsbooked++;
       totalrevenue += finalbill;


       if (customercount == 1) {
           highestbill = finalbill;
           lowestbill = finalbill;
       } else {
           if (finalbill > highestbill)
               highestbill = finalbill;
           if (finalbill < lowestbill)
               lowestbill = finalbill;
       }


       customercount++;
   }


   printf("\n------- Hotel Summary ---------\n");
   printf("Total Rooms Booked: %d\n", totalroomsbooked);
   printf("Total Revenue: ₹%.0f\n", totalrevenue);
   printf("Highest Bill: ₹%.0f\n", highestbill);
   printf("Lowest Bill: ₹%.0f\n", lowestbill);
   printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");


   return 0;
}

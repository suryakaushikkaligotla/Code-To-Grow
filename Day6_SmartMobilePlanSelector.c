#include <stdio.h>

int main() {
    int student_status, corporate_status;
    double data_used;
    double base_cost = 0.0;
    double extra_cost = 0.0;
    double plan_limit = 0.0;
    const char *plan_name = "TBD";
    double extra_charge;
    double extra_data;
    double discount = 0.0;
    double total_bill;
    double discount_amount;
    double final_bill;

    // Determine the type of plan suited based on usage
    printf("Enter total data used in GB: ");
    if (scanf("%lf", &data_used) != 1) return 0; 

    printf("Enter student status (1 for yes, 0 for no): ");
    if (scanf("%d", &student_status) != 1) return 0;

    printf("Enter corporate status (1 for yes, 0 for no): ");
    if (scanf("%d", &corporate_status) != 1) return 0;

    if (data_used > 100.0) {
        printf("Excessive Usage - Plan not allowed\n");
        return 0;
    } else {
        printf("Usage within limit.\n");
    }

    // Plan details
    if (data_used < 30.0) {
        plan_name = "Silver";
        base_cost = 299.0;
        extra_cost = 50.0;
        plan_limit = 30.0;
    } 
    else if (data_used <= 60.0) {
        plan_name = "Gold";
        base_cost = 499.0;
        extra_cost = 40.0;
        plan_limit = 60.0;
    } 
    else {
        plan_name = "Platinum";
        base_cost = 799.0;
        extra_cost = 30.0;
        plan_limit = 100.0;
    }

    // Calculate extra data and charges
    extra_data = data_used - plan_limit;
    if (extra_data < 0.0) extra_data = 0.0;

    extra_charge = extra_data * extra_cost;
    total_bill = base_cost + extra_charge;

    // Apply discount
    if (student_status == 1) {
        discount = 15.0;
    } else if (corporate_status == 1) {
        discount = 10.0;
    } else {
        discount = 0.0;
    }

    discount_amount = (discount / 100.0) * total_bill;
    final_bill = total_bill - discount_amount;

    // Print final bill
    printf("\n-------User Plan Summary-------\n");
    printf("Data Used: %.2f GB\n", data_used);
    printf("Selected Plan: %s\n", plan_name);
    printf("Base Cost: ₹%.2f\n", base_cost);
    printf("Plan Limit: %.2f GB\n", plan_limit);
    printf("Extra Data Used: %.2f GB\n", extra_data);
    printf("Extra Data Charge: ₹%.2f\n", extra_charge);
    if (discount > 0.0) {
        printf("Discount Applied: %.0f%% (₹%.2f)\n", discount, discount_amount);
    } else {
        printf("Discount Applied: None\n");
    }
    printf("Final Bill: ₹%.2f\n", final_bill);

    return 0;
}

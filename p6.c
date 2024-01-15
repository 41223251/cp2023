#include <stdio.h>

int main() {
    char id[10];         // Variable to store employee ID (up to 10 characters)
    int hour = 10;       // Set working hours to 10
    double value = 300;   // Set hourly salary to 300
    double salary;        // Variable for total salary

    // Set employee ID to "0309"
    strcpy(id, "0309");

    // Calculate total salary
    salary = value * hour;

    // Print employee ID and salary
    printf("\nEmployees ID = %s\nSalary = U$ %.2lf\n", id, salary);

    return 0;
}

#include <stdio.h>

int main() {
    int days, years, weeks;

    days = 2210; // Total number of days

    // Converts days to years, weeks, and days
    years = days / 365; // Calculate years
    weeks = (days % 365) / 7; // Calculate weeks
    days = days - ((years * 365) + (weeks * 7)); // Calculate remaining days

    // Print the results
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", days);

    return 0;
}

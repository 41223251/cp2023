#include<stdio.h>

int main()
{
    int x, y, z;

    // Prompt the user to input the three sides of a triangle
    printf("Input the three sides of a triangle:\n");

    // Read the input values for x, y, and z
    scanf("%d %d %d", &x, &y, &z);

    // Check if the triangle is a right angle triangle
    if ((x*x) + (y*y) == (z*z) || (x*x) + (z*z) == (y*y) || (y*y) + (z*z) == (x*x))
    {
        // If the condition is true, print that it's a right angle triangle
        printf("It is a right angle triangle!\n");
    }
    else
    {
        // If the condition is false, print that it's not a right angle triangle
        printf("It is not a right angle triangle!\n");
    }

    return 0; // End of the program
}
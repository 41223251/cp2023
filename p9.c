#include <stdio.h>
int main() {
    int n[9], i, x;

    // Input the first number of the array
    printf("Input the first number of the array:\n");
    scanf("%d", &x);

    // Fill the array with values based on the input
    for(i = 0; i < 5; i++) {
        n[i] = x;
        x = 3 * x;
    }

    // Print the array values
    for(i = 0; i < 5; i++) {
        printf("n[%d] = %d\n", i, n[i]);
    }

    return 0;
}
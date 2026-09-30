/*
 * #3 Odd or even checker
 * 
 * Checks whether a number is odd or even.
 */
#include <stdio.h>

int main(void) {
    int input = 0;

    // converts chars to their ascii form :cry:
    printf("Enter a number: ");
    scanf("%d", &input);

    switch (input % 2) {
        case 0:
            printf("Even\n");
            break;
        case 1:
            printf("Odd\n");
            break;
        default: 
            printf("Invalid Input\n");
            break;
    }

    return 0;
}
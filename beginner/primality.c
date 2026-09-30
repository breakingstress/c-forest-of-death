/*
 * #4 Primality Checker
 *
 * Checks whether a number is prime or composite
 */
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int primality_checker(int);

int main(void) {
    int x = 0;

    // prompt
    printf("Enter number:");
    scanf("%d", &x);

    const char *primality = (primality_checker(x) == TRUE) ? "Prime" : "Composite";

    printf("%s\n", primality);

    return 0;
}

// returns true if prime, false if composite
int primality_checker(int n) {
    if (n <= 1) {
        return FALSE;
    }

    if (n <= 3) {
        return TRUE;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return FALSE;
        }
    }

    return TRUE;
}
/*
 * #20 Armstrong number
 *
 * Date: 16/08/26
 * 
 * Determines whether a number is a nacissistic.
 * 
 * An armstrong/narcissistic number is a number whose sum of it's own digits,
 * individually cubed, equals itself.
 * 
 * 153 = 1^3 + 5^3 + 3^3
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define CUBED(X) (X*X*X)

bool is_armstrong(int);

int main(void) {
    int x = 153,
        y = 1,
        z = 345;

    printf("%d: %d\n", x, is_armstrong(x));
    printf("%d: %d\n", y, is_armstrong(y));
    printf("%d: %d\n", z, is_armstrong(z));

    return 0;
}

bool is_armstrong(int n) {
    int size = (int)(ceil(log10(n)+1)*sizeof(char));
    int sum = 0;
    int x = 0;
    char str_f[size];
    
    sprintf(str_f, "%d", n);

    for (int i = 0; i < size; i++) {
        x = atoi(str_f[i]);
        printf("%d\n", x);
        sum += CUBED(x);
    }

    printf("%d\n", sum);

    if (sum == n) return true;
    
    return false;
}
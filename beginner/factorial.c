/* 
 * Factorial Calculator
 * 
 * Date: 11/08/26
 * 
 * Calculates the factorial of a given natural number using recursion.
 */
#include <stdio.h>

size_t factorial(size_t n);

int main(void) {
    size_t input;
    
    printf("> ");
    scanf("%ld", &input);

    printf("%ld: %ld\n", input, factorial(input));

    return 0;
}

size_t factorial(size_t n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}
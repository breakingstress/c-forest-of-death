/*
 * #8 Fibonacci Generator
 *
 * Date: 14/08/26
 * 
 * Input a number and generate a fibonacci sequence.
 */
#include <stdio.h>

int fibonacci(size_t n);

int main(void) {
    size_t input;

    printf("Fibonnaci term: ");
    scanf("%ld", &input);

    printf("Fibonnaci(%ld): %d\n", input, fibonacci(input));

    return 0;
}

int fibonacci(size_t n) {
    switch (n) {
        case 0:
            return 0;
        case 1:
        case 2:
            return 1;
        default:
            return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
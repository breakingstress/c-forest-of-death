/*
 * #7a Swap Two Numbers
 *
 * Date: 14/08/26
 * 
 * Swaps 2 numbers.
 */
#include <stdio.h>

int main(void) {
    int x, y;

    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    int t = x; // temporarily holds x

    // swap
    x = y;
    y = t;

    printf("x: %d\n", x);
    printf("y: %d\n", y);

    return 0;
}
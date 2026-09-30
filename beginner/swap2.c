/*
 * #7b Swap Two Numbers
 *
 * Date: 14/08/26
 * 
 * Swaps 2 numbers, but w/ pointers...
 */
#include <stdio.h>

int main(void) {
    int x, y;
    int *xp = &x,
        *yp = &y;

    printf("x: ");
    scanf("%d", xp);
    printf("y: ");
    scanf("%d", yp);

    int temp = *xp;

    // swap
    x = *yp;
    y = temp;

    printf("x: %d\n", x);
    printf("y: %d\n", y);


    return 0;
}
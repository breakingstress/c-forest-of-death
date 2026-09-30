/*
 * #19 Sum of Digits
 * 
 * Date: 14/08/26
 * 
 * Calculates the sum of an array of ints
 */
#include <stdio.h>

int sum(int[], int);

int main(void) {
    int x[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d\n", sum(x, 10));
}

/* Calculates the sum of an array of integers and returns it */
int sum(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) { sum += arr[i]; }

    return sum;
}
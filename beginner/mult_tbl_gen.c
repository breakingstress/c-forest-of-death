/*
 * #5 Multiplication Table Generator
 * 
 * Date: 08/14/26
 * 
 * Enter a number and return a table of all it's multiples from 1-12.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 12

void mult_tbl_gen(int n);

int main(void) {
    int input;

    fprintf(stdout, "Enter a number: ");
    scanf("%d", &input);

    mult_tbl_gen(input);

    return EXIT_SUCCESS;
}

void mult_tbl_gen(int n) {
    for (int i = 1; i < MAX + 1; i++) {
        fprintf(stdout, "%dx%02d = %-6d\n", n, i, n * i);
    }
}
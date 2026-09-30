/*
 * #12 String Reversal
 *
 * Date: 14/08/26
 * 
 * 2 functions that reverse a string by returning or modifying it.
 */
#include <stdio.h>
#include "strlen.h"

void str_rvrs(char *string);

int main(void) {
    char string[6] = "hello";

    str_rvrs(string);

    printf("%s\n", string);

    return 0;
}

/* Modifies the string in-place given by reversing it. */
void str_rvrs(char *string) {
    char temp;
    int j = 0;
    size_t size = str_len(string);

    /*
     * Traverses the arr frm the strt & end simultaneously to the middle.
     * Swaps the start and end chars till the end.
     */
    for (size_t i = 0; i < size; i++) {
        j = (size - 1) - i;
        temp = string[j];

        if (temp == string[i]) {
            return;
        }

        string[j] = string[i];
        string[i] = temp;
    }
}
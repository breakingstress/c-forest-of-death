/*
 * #13 Palindrome Checker
 *
 * Date: 16/08/26
 * 
 * Checks whether a number is a palindrome or not.
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool is_palindrome(int);
char *inplace_strrev(char *);

int main(void) {
    int x = 123,
        y = 252,
        z = -121;
    
    printf("%d: %d\n", x, is_palindrome(x));
    printf("%d: %d\n", y, is_palindrome(y));
    printf("%d: %d\n", z, is_palindrome(z));

    return 0;
}

/*
 * Checks whether a number is palindrome or not
 *
 * Returns true if is, false if not.
 */
bool is_palindrome(int n) {
    if (n < 0) return false;

    /* The size of the str v. of the int*/
    int size = (int)((ceil(log10(n)) + 1)*sizeof(char));
    char str_format[size];
    char str_rvrsd[size];

    sprintf(str_format, "%d", n); // converts to int to str
    strcpy(str_rvrsd, str_format);
    inplace_strrev(str_rvrsd);

    if (strcmp(str_format, str_rvrsd) == 0) return true;
    
    return false;
}

/*
 * Reverses a string in place.
 * 
 * Source:
 * https://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux
 */
char *inplace_strrev(char *string) {
    char *start, *end;

    for (start = string, end = string + strlen(string) - 1; end > start; ++start, --end) {
            *start ^= *end;
            *end ^= *start;
            *start ^= *end;
    }

    return string;
}
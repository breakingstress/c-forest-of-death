/*
 * #11 Custom strlen()
 *
 * Date: 14/08/26
 * 
 * A custom strlen function.
 */
#include "strlen.h"

/*  
 * Returns the length of a given string 
 * (excluding the null terminator)
 */
size_t str_len(const char* string) {
    size_t counter = 0;

    while (string[counter] != '\0') {
        counter++;
    }

    return counter;
}

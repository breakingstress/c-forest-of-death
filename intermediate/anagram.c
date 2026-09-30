/*
 * #32 Anagram Checker
 *
 * Date: 16/08/26
 * 
 * Determines whether 2 strings are anagrams of each other.
 * 
 * 1st solution: sorts both strings alphabetically and compares them.
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_anagram(char *, char *);
char *selection_sort(char *);

int main(void) {
    char x[] = "listen";
    char a[] = "word";
    char y[] = "silent";

    printf("%s, %s: %d\n", x, y, is_anagram(x, y));
    printf("%s, %s: %d\n", a, x, is_anagram(x, a));

    return 0;
}

/* Re arranges a string into alphabetical order using selection sort */
char *selection_sort(char *str) {
    size_t size = strlen(str);
    char temp;

    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (str[j] < str[i]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    return str;
}

/* Returns true if the compared strings are anagrams */
bool is_anagram(char *str1, char *str2) {
    /*
     * Copies the strings, sorts them alphabetically
     * then compares them. Returns t if anagram.
     */
    size_t size1 = strlen(str1),
           size2 = strlen(str2);

    char str1_c[size1 + 1],
         str2_c[size2 + 1];

    strcpy(str1_c, str1);
    strcpy(str2_c, str2);

    selection_sort(str1_c);
    selection_sort(str2_c);

    if (strcmp(str1_c, str2_c) == 0) return true;

    return false;
}

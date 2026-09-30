/*
 * #10 Number Guessing Game
 *
 * Date: 14/08/26
 * 
 * Input a number and generate a fibonacci sequence.
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL)); /* Changes seed depending on time */

    size_t number;
    size_t rand_num = (rand() % 10) + 1; /* Random number 1-10 */

    /* Prompts till the right number is guessed*/
    do {
        printf("Guess a number between 1 and 10: ");
        scanf("%lu", &number);
        while (getchar() != '\n'); /* Clears stdin till \n (inclusive)*/
    } while (number != rand_num);

    puts("You guessed correctly!\n");

    return EXIT_SUCCESS;
}
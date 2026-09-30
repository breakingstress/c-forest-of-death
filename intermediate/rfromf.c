/*
 * #47 Read from a file
 * 
 * Created by breakingstress on 14/08/26
 * 
 * Reads each line from agiven file and prints out
 */
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(void) {
    FILE *fptr = fopen("file.txt", "r");

    // Validation
    if (fptr == NULL) {
        fprintf(stderr, "Error: Unable to open file.");

        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];

    // reading the file
    while (fgets(buffer, BUFFER_SIZE, fptr)) {
        printf("%s", buffer);
    }
    puts("");

    fclose(fptr);

    return EXIT_SUCCESS;
}
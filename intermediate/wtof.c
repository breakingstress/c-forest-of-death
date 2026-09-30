/*
 * #46 Write to a file
 * 
 * Created by breakingstress on 14/08/26
 * 
 * This file writes to a file!
 */
#include <stdio.h>

#define BUFFER_SIZE 64

int main(void) {
    FILE *file_ptr = fopen("file.txt", "w");
    char buffer[BUFFER_SIZE];

    printf("> ");
    fgets(buffer, BUFFER_SIZE, stdin);
    fputs(buffer, file_ptr);

    fclose(file_ptr);
}
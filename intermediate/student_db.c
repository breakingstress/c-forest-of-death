/* #6 Student Database -> Struct Projects */

/*
 * @author breakingstress
 * @date 9/30/26
 */

/*
 * - Add student x
 * - Print all students x
 * - Search by ID
 * - Find highest grade
 * - Calculate average grade
 */
#include <stdio.h>
#include <stdlib.h>

#define RED_TERMINAL_TEXT   "\e[0;31m"
#define RESET_TERMINAL_TEXT "\033[0m"

typedef struct {
    size_t grade;
    char *id;
    char *name;
} student;

typedef struct {
    student *database;
    size_t size;
    size_t capacity;
} student_database;

void print_student(student *);
void print_all_students(student_database *);
void add_student(student_database *,char *, char *, size_t);
void alloc_err_msg(char *);
student *get_id(student_database *, const char *);
student *get_highest_grade(student_database *);
size_t calc_avg_grade(student_database *);

int main(void) {
    /* Initialise student database */
    student *x;

    if ((x = (student *) malloc(sizeof(student) * 1)) == NULL) {
        alloc_err_msg("students");
    }

    student_database database = {
        .database = x,
        .size = 1,
        .capacity = 0,
    };

    /* Add test student */
    add_student(&database, "John Doe", "0001", 100);

    print_student(database.database);
    print_all_students(&database); // testing for the student
}

/* Adds a student to the given student database */
void add_student(student_database *db, char *name, char *id, size_t grade) {
    /* Initialise the student */
    student new_student = {
        .name = name,
        .id = id,
        .grade = grade,
    };

    /* If the capacity isn't full, append the student and increase the capacity */
    if (!(db->size == db->capacity)) {
        db->database[db->capacity] = new_student;
        db->capacity++;
        return;
    }

    /* If the capacity is full, resize the array to fit another student */
    student *resized_db;

    if ((resized_db = (student *) realloc(db->database, sizeof(student) * (db->size+1))) == NULL) {
        db->capacity++;
        db->size++;

        db->database = resized_db;

        db->database[db->size] = new_student;
    }
}

/* Prints out error message in red when allocating memory returns NULL */
void alloc_err_msg(char *str) {
    fprintf(stderr,
        RED_TERMINAL_TEXT "\nError allocating memory for %s" RESET_TERMINAL_TEXT "\n",
        str);
}

void print_student(student *s) {
    printf("\nNAME: %s\nID: %s\nGRADE: %llu\n",
        s->name, s->id, s->grade);
}

void print_all_students(student_database *sdb) {
    student current_student;

    puts("-----------------------------------");
    for (size_t i = 0; i<sdb->capacity; i++) {
        current_student = sdb->database[i];
        printf("%s: %s\n", current_student.id, current_student.name);
    }
}
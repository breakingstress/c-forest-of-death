/* Just practicing structs */
#include <stdio.h>

struct Student {
    char *name;
    char *id;
    size_t age;
    size_t grade;
};

/* prints out a students information with a given struct pointer to said student */
void print_student(struct Student *student);

int main(void) {
    struct Student test_student = { 
        "John Doe",
        "0123456789",
        18,
        50,
    };

    print_student(&test_student); 

    return 0;
}

void print_student(struct Student *student) {
    printf("Name: %s, %zu\nID: %s\nGrade: %zu\n",
        student->name, student->age, student->id, student->grade);
}
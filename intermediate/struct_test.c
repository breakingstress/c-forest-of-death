#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} vec3;

int main() {
    vec3 vector = { 3, 2, 1 };
    vec3 *vec_ptr = &vector;

    /* Accessing w/ . notation */
    printf("vector: (%d, %d, %d)\n", vector.x, vector.y, vector.z);
    /* Accessing through pointer to struct (arrow operator) */
    printf("vector: (%d, %d, %d)\n", vec_ptr->x, vec_ptr->y, vec_ptr->z);

    return 0;
}
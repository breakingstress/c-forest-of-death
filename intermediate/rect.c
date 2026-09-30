#include <stdio.h>

struct rect {
    size_t width;
    size_t height;
};

size_t perimeter(struct rect);
size_t area(struct rect);
void print_rect(struct rect);

int main (void) {
    struct rect x = { 10, 20 };

    print_rect(x);
    printf("Area: %zu\nPerimeter: %zu\n", area(x), perimeter(x));

    return 0;
}

void print_rect(struct rect r) {
    printf("Height: %zu\nWidth: %zu\n", r.height, r.width);
}

size_t perimeter(struct rect r) {
    return 2 * (r.width + r.height);
}

size_t area(struct rect r) {
    return r.width * r.height;
}
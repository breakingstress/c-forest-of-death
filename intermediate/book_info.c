#include <stdio.h>

struct book_data {
    char* title;
    char* author;
    char* isbn;
    size_t price;
};

void print_book_data(struct book_data *);

int main(void) {
    struct book_data example_book;
    example_book.title = "I'm Obsessed";
    example_book.author = "Obsessed Guy";
    example_book.isbn = "totally_real_isbn";
    example_book.price = 1099;

    print_book_data(&example_book);

    return 0;
}

void print_book_data(struct book_data *book) {
    printf("Title: %s\nAuthor: %s\nISBN: %s\nPrice: %2.2f$\n",
        book->title, book->author, book->isbn, ((float) book->price)/100);
}
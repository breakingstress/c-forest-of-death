#include <stdio.h>
#include <stdbool.h>

typedef enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBOR,
    DECEMBER,
} Months;

struct date {
    size_t day;
    size_t month;
    size_t year;
};

void print_date(struct date *);
_Bool is_leap_year(struct date *);
_Bool is_valid_date(struct date *);

int main(void) {

    return 0;
}

void print_date(struct date *date) {
    printf("%2d/%2d/%4d", date->day, date->month, date->year);
}

_Bool is_leap_year(struct date *date) {
    if (date->year % 400) return true;

    if (date->year % 4 && !(date->year % 100)) return true;

    return false;
}

_Bool is_valid_date(struct date *date) {
    if (date->month > DECEMBER) return false;
    if (date->day > 31) return false;
    if (is_leap_year(date->year) && date->month == FEBRUARY && date->day != 29) 
    return false;
    if (date->month == FEBRUARY && date->day > 28) return false;
    
    switch (date->month % 2) {
        case 0:
            if (date->day > 30) return false;
        case 1:
            if (date->day > 31) return false;
    }

    return true;
}
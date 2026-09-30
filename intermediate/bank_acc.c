/* Very lazy... I'll make a bigger one later... just practicing structs */

/* note: finish withdrawl and deposit option functions, add some comments... */

#include <stdio.h>

#define RED_TERMINAL_TEXT   "\e[0;31m"
#define RESET_TERMINAL_TEXT "\033[0m"

#define TRUE  1
#define FALSE 0

struct account {
    char *number;
    char *holder;
    float balance;
};

void display_balance(struct account);
void display_options(void);
void withdrawal_options(struct account);
void deposit_options(struct account);
void deposit(struct account, int);
int withdraw(struct account, int);
float from_minor(int);
void invalid_option_err_msg(void);

int main(void) {
    struct account acc = {
        "00000000000",
        "John Doe",
        1278645,
    };

    int running = TRUE;

    while (running) {
        /* Display account options */
        int input;

        display_options();
        printf("\n> ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                display_balance(acc);
                break;
            case 2:
                deposit_options(acc);
                break;
            case 3:
                withdrawal_options(acc);
                break;
            case 4:
                puts("Bye!");
                running = FALSE;
                break;
            default:
                invalid_option_err_msg();
                while (getchar() != '\n')
                fflush(stdin);
                break;
        }
    }

    return 0;
}

float from_minor(int balance) { return ((float) balance) / 100; }

void display_options() { puts("\n1. View Balance\n2. Deposit\n3. Withdraw\n4. Exit"); }

void display_balance(struct account acc) {
    if (acc.balance < 0) {
        printf("\n" RED_TERMINAL_TEXT "ACCOUNT OVERDRAFT" RESET_TERMINAL_TEXT "\n%s | %s\nBalance = %.2f$\n\n",
               acc.holder, acc.number, from_minor(acc.balance));
    } else {
        printf("\n%s | %s\nBalance = %.2f$\n\n",
               acc.holder, acc.number, from_minor(acc.balance));
    }
}

int withdraw(struct account acc, int amount) {
    if (0 > acc.balance - amount) {
        puts("You are now in overdraft!");
    }

    acc.balance -= amount;

    return amount;
}

void withdrawal_options(struct account acc) {
    while (TRUE) {
        int input;

        printf("1. 5$\t2. 10$\n3. 20$\t4. 50$\n5. 100$ \t6. 200$"); 
        scanf("%d", &input);

        switch (input) {
            case 1:
                withdraw(acc, 5);
                break;
            case 2:
                withdraw(acc, 10);
                break;
            case 3:
                withdraw(acc, 20);
                break;
            case 4:
                withdraw(acc, 50);
                break;
            case 5:
                withdraw(acc, 100);
                break;
            case 6:
                withdraw(acc, 200);
                break;
            default:
                invalid_option_err_msg();

        }
    }
}

void deposit(struct account acc, int amount) { acc.balance += amount; }

void deposit_options(struct account acc) {
    while (TRUE) {
        int input;

        printf("1. 5$\t2. 10$\n3. 20$\t4. 50$\n5. 100$ \t6. 200$"); 
        scanf("%d", &input);

        switch (input) {
            case 1:
                deposit(acc, 5);
                break;
            case 2:
                deposit(acc, 10);
                break;
            case 3:
                deposit(acc, 20);
                break;
            case 4:
                deposit(acc, 50);
                break;
            case 5:
                deposit(acc, 100);
                break;
            case 6:
                deposit(acc, 200);
                break;
            default:
                invalid_option_err_msg();

        }
    }
}

void invalid_option_err_msg(void) {
    fprintf(stderr, RED_TERMINAL_TEXT "\nInvalid Input\n\n" RESET_TERMINAL_TEXT);
}
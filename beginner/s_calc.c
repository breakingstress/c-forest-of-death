/*
 * Name: #2 Simple Calculator CLI
 * Date: 08/04/26
 * 
 * CLI simple calculator that prompts the user for 2 operands and an operand. 
 */
#include <stdio.h>

int main(void) {
    double r_operand = 0,
           l_operand = 0;
    char operator;

    // prompts
    printf("Left operand: ");
    scanf("%lf", &l_operand);
    printf("Right operand: ");
    scanf("%lf", &r_operand);
    printf("Operator: ");
    scanf(" %c", &operator);

    switch (operator) {
        // Multiplication
        case 42:
            printf("Result: %lf\n", l_operand * r_operand);
            break;
        // Addition
        case 43:
            printf("Result: %lf\n", l_operand + r_operand);
            break;
        // Subtraction
        case 45:
            printf("Result: %lf\n", l_operand - r_operand);
            break;
        // Division
        case 47:
            printf("Result: %lf\n", l_operand / r_operand);
            break;
        default:
            printf("Invalid operator/operand(s)\n");
            break;
    }

    return 0;
}
#include "calculator.h"
#include <stdio.h>

void print_menu() {
    printf("\nCalculator Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Fraction Product\n");
    printf("5. Factorial\n");
    printf("6. Square\n");
    printf("0. Exit\n");
    printf("Choose operation: ");
}

int main() {
    int choice, a, b, num1, num2, den1, den2;
    Fraction f1, f2, result;

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                return 0;
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", add(a, b));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", difference(a, b));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", multiply(a, b));
                break;
            case 4:
                printf("Enter first fraction (numerator denominator): ");
                scanf("%d %d", &num1, &den1);
                printf("Enter second fraction (numerator denominator): ");
                scanf("%d %d", &num2, &den2);
                f1 = create_fraction(num1, den1);
                f2 = create_fraction(num2, den2);
                result = product_fractions(f1, f2);
                printf("Result: %d/%d\n", result.numerator, result.denominator);
                break;
            case 5:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Result: %d\n", factorial(a));
                break;
            case 6:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Result: %d\n", square(a));
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

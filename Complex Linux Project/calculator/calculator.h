#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);
int multiply(int a, int b);
int difference(int a, int b);
int factorial(int n);
int square(int n);

typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction create_fraction(int num, int den);
Fraction product_fractions(Fraction f1, Fraction f2);

#endif
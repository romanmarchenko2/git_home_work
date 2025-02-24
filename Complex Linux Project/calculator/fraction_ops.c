#include "calculator.h"
#include <stdlib.h>

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void simplify_fraction(Fraction* f) {
    if (f->denominator < 0) {
        f->numerator = -f->numerator;
        f->denominator = -f->denominator;
    }
    int divisor = gcd(f->numerator, f->denominator);
    f->numerator /= divisor;
    f->denominator /= divisor;
}

Fraction create_fraction(int num, int den) {
    Fraction f = {num, den};
    simplify_fraction(&f);
    return f;
}

Fraction product_fractions(Fraction f1, Fraction f2) {
    Fraction result = {
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    };
    simplify_fraction(&result);
    return result;
}
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);

    static double power(double base, double exp);
    static double root(double value, int degree);

    static double sine(double angleRad);
    static double cosine(double angleRad);
    static double tangent(double angleRad);
};

#endif

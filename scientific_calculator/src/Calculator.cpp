#include "Calculator.h"
#include <cmath>
#include <stdexcept>

double Calculator::add(double a, double b) { return a + b; }
double Calculator::subtract(double a, double b) { return a - b; }
double Calculator::multiply(double a, double b) { return a * b; }

double Calculator::divide(double a, double b) {
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}

double Calculator::power(double base, double exp) {
    return std::pow(base, exp);
}

double Calculator::root(double value, int degree) {
    if (degree <= 0) throw std::runtime_error("Invalid root degree");
    if (value < 0 && degree % 2 == 0)
        throw std::runtime_error("Even root of negative number");
    return std::pow(value, 1.0 / degree);
}

double Calculator::sine(double angleRad) {
    return std::sin(angleRad);
}

double Calculator::cosine(double angleRad) {
    return std::cos(angleRad);
}

double Calculator::tangent(double angleRad) {
    if (std::cos(angleRad) == 0)
        throw std::runtime_error("Undefined tangent");
    return std::tan(angleRad);
}

#include "Menu.h"
#include "Calculator.h"
#include "InputValidator.h"
#include <iostream>
#include <cmath>

void Menu::run() {
    while (true) {
        std::cout <<
            "\n1) Arithmetic\n2) Power\n3) Root\n4) Trigonometry\n"
            "5) Settings\n6) Exit\n";

        int c = InputValidator::getInt("Choose: ", 1, 6);

        try {
            switch (c) {
                case 1: arithmetic(); break;
                case 2: power(); break;
                case 3: root(); break;
                case 4: trigonometry(); break;
                case 5: settings(); break;
                case 6: return;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

void Menu::arithmetic() {
    double a = InputValidator::getDouble("a: ");
    double b = InputValidator::getDouble("b: ");
    std::cout << "Result: " << Calculator::add(a, b) << "\n";
}

void Menu::power() {
    double a = InputValidator::getDouble("Base: ");
    double b = InputValidator::getDouble("Exponent: ");
    std::cout << Calculator::power(a, b) << "\n";
}

void Menu::root() {
    double x = InputValidator::getDouble("Value: ");
    int n = InputValidator::getInt("Degree: ", 1, 100);
    std::cout << Calculator::root(x, n) << "\n";
}

void Menu::trigonometry() {
    double angle = InputValidator::getDouble("Angle: ");
    if (useDegrees) angle = angle * M_PI / 180.0;
    std::cout << Calculator::sine(angle) << "\n";
}

void Menu::settings() {
    int c = InputValidator::getInt("1) Degrees 2) Radians: ", 1, 2);
    useDegrees = (c == 1);
}

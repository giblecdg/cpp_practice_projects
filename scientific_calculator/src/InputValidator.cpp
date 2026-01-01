#include "InputValidator.h"
#include <iostream>
#include <limits>

double InputValidator::getDouble(const std::string& prompt) {
    double x;
    while (true) {
        std::cout << prompt;
        std::cin >> x;

        if (!std::cin.fail()) return x;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid number.\n";
    }
}

int InputValidator::getInt(const std::string& prompt, int min, int max) {
    int x;
    while (true) {
        std::cout << prompt;
        std::cin >> x;

        if (!std::cin.fail() && x >= min && x <= max) return x;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice.\n";
    }
}

#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>

class InputValidator {
public:
    static double getDouble(const std::string& prompt);
    static int getInt(const std::string& prompt, int min, int max);
};

#endif

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>

void clearScreen(), doArithmetic(), doPower(), doRoot(), doTrigonometric(), settingsMenu(), printHelp();

bool inputDouble(std::string prompt, std::string errorPrint, double &userValue), isInt(const std::string &s);

int inputUserChoice(int min, int max);

int main()
{
    clearScreen();
    std::cout << "=== SCIENTIFIC CALCULATOR ===\n";
    
    while (true)
    {
        std::cout << "\n1) Arithmetic operations (+, -, *, /)\n";
        std::cout << "2) Power (a^b)\n";
        std::cout << "3) Root (square root, n-th root)\n";
        std::cout << "4) Trigonometric functions (sin, cos, tan)\n";
        std::cout << "5) Settings (degrees/radians)\n";
        std::cout << "6) Help\n";
        std::cout << "7) Quit\n\n";
        
        // int userChoice = inputUserChoice(1, 7);
        std::string userInput;
        std::cout << "Enter your choice: ";
        std::cin >> userInput;

        if(!(isInt(userInput))) {
            std::cout << "Wrong option. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        int userChoice = std::stoi(userInput);
        
        switch (userChoice)
        {
            case 1: doArithmetic(); break;
            // case 2: doPower(); break;
            // case 3: doRoot(); break;
            // case 4: doTrigonometric(); break;
            // case 5: settingsMenu(); break;
            // case 6: printHelp(); break;
            case 7:
                clearScreen(); 
                std::cout << "Quitting...\n";
                return 0;
            default:
                std::cout << "Wrong option. Please try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                break;
        }
    }
}

void doArithmetic() 
{
    clearScreen();

    double a = 0;
    double b = 0;

    while (true) 
    {
        if (!inputDouble("Please enter a: ", "Error. This is not a number", a)) { continue; }
        if (!inputDouble("Please enter b: ", "Error. This is not a number", b)) { continue; }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        char userChoice;
        std::cout << "\n+ : ADD";
        std::cout << "\n- : SUBSTRACT";
        std::cout << "\n* : MULTIPLY";
        std::cout << "\n/ : DIVIDE\n\n";

        std::cout << "Enter your choice: ";
        std::cin >> userChoice;

        switch (userChoice) 
        {
            case '+':
                std::cout << a << " + " << b << " = " << a+b << "\n";
                break;
            case '-':
                std::cout << a << " - " << b << " = " << a-b << "\n";
                break;
            case '*':
                std::cout << a << " * " << b << " = " << a*b << "\n";
                break;
            case '/':
                if (b == 0)
                {
                    std::cout << "Error. You can't divide by 0\n";
                    break;
                }

                std::cout << a << " / " << b << " = " << a/b << "\n";
                break;
            default:
                std::cout << "Wrong option. Please try again.\n";
                break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
}

void clearScreen()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

bool inputDouble(std::string prompt, std::string errorPrint, double &userValue) 
{
    std::cout << prompt;

    if(!(std::cin >> userValue)) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen(); 
        std::cout << errorPrint << "\n" ;
        return false;
    }
    return true;
}

bool isInt(const std::string &s)
{
    if(s.empty()) return false;

    int start = (s[0] == '-') ? 1 : 0;

    if (start == 1 && s.size() == 1) return false;

    for (int i = start; i < s.size(); i++)
    {
        if (!isdigit(s[i])) return false;
    }

    return true;
}
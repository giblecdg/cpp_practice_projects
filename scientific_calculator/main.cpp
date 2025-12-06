#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

void clearScreen(), doArithmetic(), doPower(), doRoot(), doTrigonometric(), settingsMenu(), printHelp();

bool inputDouble(std::string prompt, std::string errorPrint, double &userValue);

int inputUserChoice(int min, int max);

int main()
{
    clearScreen();

    while (true)
    {

        std::cout << "=== SCIENTIFIC CALCULATOR ===\n";
        std::cout << "1) Arithmetic operations (+, -, *, /)\n";
        std::cout << "2) Power (a^b)\n";
        std::cout << "3) Root (square root, n-th root)\n";
        std::cout << "4) Trigonometric functions (sin, cos, tan)\n";
        std::cout << "5) Settings (degrees/radians)\n";
        std::cout << "6) Help\n";
        std::cout << "7) Quit\n\n";
        
        int userChoice = inputUserChoice(1, 7);
        
        switch (userChoice)
        {
            case 1: doArithmetic(); break;
            // case 2: doPower(); break;
            // case 3: doRoot(); break;
            // case 4: doTrigonometric(); break;
            // case 5: settingsMenu(); break;
            // case 6: printHelp(); break;
            case 7: clearScreen(); std::cout << "Quitting...\n"; return 0;
            default: std::cout << "\nWrong option. Please try again."; break;
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
        if (!inputDouble("Please enter a: ", "This is not a number", a)) { continue; }
        if (!inputDouble("Please enter b: ", "This is not a number", b)) { continue; }

        std::cout << a << " + " << b << " = " << a+b << "\n\n";
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

int inputUserChoice(int min, int max) 
{   
    int userChoice;

    while (true)
    {
        std::cout << "Enter your choice: ";

        if ((std::cin >> userChoice))
        {
            if (min <= userChoice && userChoice <= max)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return userChoice;
            }

            std::cout << "\nWrong option. Please try again.\n";
        }
        else
        {
            std::cout << "\nWrong option. Please try again.\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
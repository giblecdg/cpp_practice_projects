#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <chrono>
#include <thread>

void clearScreen(), doArithmetic(), doPower(), doRoot(), doTrigonometric(), settingsMenu(), printHelp();

bool inputDouble(std::string prompt, std::string errorPrint, double &userValue);

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
        
        int userChoice = inputUserChoice(1, 7);
        
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
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return 0;
            default: break;
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
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }

                std::cout << a << " / " << b << " = " << a/b << "\n";
                break;
            default:
                std::cout << "Wrong option. Please try again.\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
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

            std::cout << "Wrong option. Please try again.\n";
        }
        else
        {
            std::cout << "Wrong option. Please try again.\n";
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
#include <iostream>
#include <cstdlib>
#include <string>

void clearScreen(), doArithmetic(), doPower(), doRoot(), doTrigonometric(), settingsMenu(), printHelp();

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

        std::cout << "Enter your choice: ";

        int userChoice = 0;
        
        if(!(std::cin >> userChoice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            clearScreen(); std::cout << "Wrong option. Please try again.\n\n";
        }
        
        switch (userChoice)
        {
            // case 1: doArithmetic(); break;
            // case 2: doPower(); break;
            // case 3: doRoot(); break;
            // case 4: doTrigonometric(); break;
            // case 5: settingsMenu(); break;
            // case 6: printHelp(); break;
            case 7: clearScreen(); std::cout << "Quitting...\n\n"; return 0;
            default: clearScreen(); std::cout << "Wrong option. Please try again.\n\n"; break;
        }
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
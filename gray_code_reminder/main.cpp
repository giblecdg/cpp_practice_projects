#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

void ColumnReminder(std::vector<std::string> &Column)
{
    system("clear");

    int i = 1;
    std::string userInput;

    for (std::string value : Column)
    {
        std::cout << "Enter column n. " << i << ": ";
        std::cin >> userInput;

        if(userInput == value)
        {
            system("clear");
            std::cout << "Correct!\n";
            i++;
        }
        else
        {
            std::cout << "Wrong! Try again.\n\n";
            break;
        }
    }
}

void showCollumns(std::vector<std::string> &ABColumn, std::vector<std::string> &CDEColumn)
{
    system("clear");


    std::cout << "--- AB COLUMN ---\n";
    for (std::string value : ABColumn)
    {
        std::cout << value << "\n";
    }
    
    std::cout << "\n";

    std::cout << "--- CDE COLUMN ---\n";
    for (std::string value : CDEColumn)
    {
        std::cout << value << "\n";
    }
    
    std::cout << "\n";
}

int main()
{
    system("clear");

    std::vector<std::string> ABColumn = {"00", "01", "11", "10"};
    std::vector<std::string> CDEColumn = {"000", "001", "011", "010", "110", "111", "101", "100"};

    char userChoice;

    while (true)
    {
        std::cout << "---- Gray Code Karnaugh Map reminder ----\n";
        std::cout << "Enter Gray's collumn you want to learn.\n";
        std::cout << "1. AB Column.\n";
        std::cout << "2. CDE Column.\n";
        std::cout << "3. Show columns.\n";
        std::cout << "4. Exit\n\n";

        std::cout << "ENTER YOUR CHOICE: ";
        std::cin >> userChoice;

        switch (userChoice)
        {
        case '1':
            ColumnReminder(ABColumn);
            break;
        case '2':
            ColumnReminder(CDEColumn);
            break;
        case '3':
            showCollumns(ABColumn, CDEColumn);
            break;
        case '4':
            system("clear");
            std::cout << "Quitting...\n";
            return 0;
        default:
            system("clear");
            std::cout << "Wrong choice. Try again.\n\n";
            break;
        }
    }
}
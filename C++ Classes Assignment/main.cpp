#include <iostream>
#include "Database.h"

/**
 * @brief Entry point for the program.
 *
 * This method acts as the main user interface loop for managing a database of animals.
 * It provides a menu-driven interface for users to perform operations such as creating
 * new animals, displaying all animals, searching for animals by name, and displaying
 * animals filtered by type. The program terminates when the user chooses the quit option.
 *
 * @return Integer status code indicating the success or failure of the program. Returns 0
 *         to indicate successful execution.
 */
int main() {
    Database database;
    bool quit = false;
    while (!quit) {
        std::cout << "\n1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cout << "Enter type (0 for CAT, 1 for DOG): ";
                int t;
                std::cin >> t;
                database.Create(static_cast<Animal::eType>(t));
                break;
            }
            case 2:
                database.DisplayAll();
            break;
            case 3: {
                std::cout << "Enter name to search: ";
                std::string name;
                std::cin >> name;
                database.Display(name);
                break;
            }
            case 4: {
                std::cout << "Enter type (0 for CAT, 1 for DOG): ";
                int t;
                std::cin >> t;
                database.Display(static_cast<Animal::eType>(t));
                break;
            }
            case 5:
                quit = true;
            break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}

#pragma once
#include <vector>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

/**
 * @class Database
 * @brief Class that manages a collection of Animal objects, allowing creation,
 *        retrieval, and display of the objects based on certain criteria.
 *
 * The Database class is responsible for storing dynamically created Animal objects,
 * offering methods to create new animals of specific types, and providing various
 * options to display the stored animals based on certain conditions like name or type.
 */
class Database {
    /**
     * Destructor for the Database class.
     *
     * Cleans up dynamically allocated memory by deleting all objects
     * stored in the `objects` vector. Ensures that there are no memory leaks
     * by properly deallocating all resources associated with the stored
     * `Animal` objects.
     */
public:
    ~Database();

    /**
     * @brief Creates an instance of a specific type of animal and stores it in the database.
     *
     * This method allows the creation of an animal object of the specified type (e.g., CAT or DOG).
     * The created animal is initialized using user input and added to the database for management.
     *
     * @param type The type of animal to create, specified as one of the values from Animal::eType.
     *             Supported types are Animal::eType::CAT and Animal::eType::DOG.
     */
    void Create(Animal::eType type);

    /**
     * Displays all the Animal objects stored in the database.
     *
     * This method iterates through the collection of Animal
     * objects in the database and outputs their details to the
     * standard output. Each object is displayed using its Write
     * method followed by a separator line for clarity.
     */
    void DisplayAll();

    /**
     * Displays the details of an animal in the database that matches the specified name.
     * If no matching animal is found, no output is displayed.
     *
     * @param name The name of the animal to be searched for and displayed.
     */
    void Display(const std::string& name);

    /**
     * Displays all animals in the database that match the specified type.
     *
     * @param type The type of animals to display, specified using the Animal::eType enumeration.
     */
    void Display(Animal::eType type);

    /**
     * @brief A container for storing pointers to dynamically allocated Animal objects.
     *
     * This vector is used by the Database class to manage and store a collection of Animal-derived objects.
     * It allows operations such as adding, iterating, searching, and displaying Animal objects of various types.
     */
private:
    std::vector<Animal*> objects;
};

/**
 * @brief Destructor for the Database class.
 *
 * This destructor is responsible for cleaning up dynamically allocated Animal objects
 * stored in the `objects` vector. It iterates through the vector and deletes each Animal
 * pointer to ensure proper deallocation of memory and to prevent memory leaks.
 */
inline Database::~Database() {
    for (Animal* obj : objects) {
        delete obj;
    }
}

/**
 * @brief Creates an Animal object of the specified type and adds it to the database.
 *
 * This method dynamically creates an instance of an Animal-derived class (e.g., Cat or Dog)
 * based on the given type. It then prompts the user for additional details for the object
 * using the console input/output streams. Once the details are provided, the object is
 * added to the database's list of existing objects.
 *
 * @param type Specifies the type of animal to create. It should be a value from the Animal::eType enumeration.
 */
inline void Database::Create(Animal::eType type) {
    Animal* obj = nullptr;
    switch (type) {
        case Animal::eType::CAT:
            obj = new Cat;
        break;
        case Animal::eType::DOG:
            obj = new Dog;
        break;
    }
    if (obj) {
        obj->Read(std::cout, std::cin);
        objects.push_back(obj);
    }
}

/**
 * @brief Displays information about all animals in the database.
 *
 * This method iterates through the vector of stored `Animal` objects
 * and calls the `Write` method of each object to print its details
 * to the standard output stream. Each animal's information is followed
 * by a separator line for better readability.
 */
inline void Database::DisplayAll() {
    for (Animal* obj : objects) {
        obj->Write(std::cout);
        std::cout << "-------------------\n";
    }
}

/**
 * Displays information about all animals in the database that match a given name.
 * If the name of an animal matches the provided name, its details are printed.
 *
 * @param name The name of the animal to search and display.
 */
inline void Database::Display(const std::string& name) {
    for (Animal* obj : objects) {
        if (obj->GetName() == name) {
            obj->Write(std::cout);
            std::cout << "-------------------\n";
        }
    }
}

/**
 * Displays all the Animal objects in the database that match the given type.
 * Iterates through all stored objects and prints details of each with a matching type.
 * A separator line is added between each object's details.
 *
 * @param type The type of animal to display (e.g., CAT, DOG).
 */
inline void Database::Display(Animal::eType type) {
    for (Animal* obj : objects) {
        if (obj->GetType() == type) {
            obj->Write(std::cout);
            std::cout << "-------------------\n";
        }
    }
}

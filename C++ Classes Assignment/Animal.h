#pragma once
#include <string>
#include <iostream>

/**
 * @class Animal
 * @brief Represents a base class for different types of animals.
 *
 * This is an abstract class that provides a common interface for specific animal types
 * such as Cat and Dog. The base class includes properties such as the name of the
 * animal and its lifespan, and it declares virtual functions for input/output operations
 * and for retrieving the type of the animal.
 */
class Animal {
    /**
     * @brief Virtual destructor for the Animal class.
     *
     * Ensures proper cleanup of derived class resources when a derived class
     * object is deleted through a base class pointer.
     */
public:
    virtual ~Animal() = default;

    /**
     * @enum eType
     * @brief Enumeration representing the type of animal.
     *
     * Defines the type of animals that can be represented in the system.
     * Possible values are:
     * - `CAT`: Represents a cat.
     * - `DOG`: Represents a dog.
     */
    enum class eType { CAT, DOG };

    /**
     * @brief Default constructor for the Animal class.
     *
     * Initializes an Animal object with default values.
     *
     * @return Instance of Animal class with default initialization.
     */
    Animal() = default;

    /**
     * Constructs an Animal object by initializing its name and lifespan.
     *
     * @param name The name of the animal.
     * @param lifespan The average lifespan of the animal in years.
     * @return An initialized instance of the Animal class.
     */
    Animal(const std::string& name, int lifespan) : name(name), lifespan(lifespan) {}
    /**
     * Reads the attributes of the Animal object from the input stream and writes prompts to the output stream.
     * This method requests the user to input specific details of the Animal object, such as name and lifespan.
     *
     * @param ostream The output stream to write prompts and messages to the user.
     * @param istream The input stream from which the user provides the data for the Animal attributes.
     */
    virtual void Read(std::ostream& ostream, std::istream& istream);

    /**
     * Writes the details of the Animal object to the provided output stream.
     * This method outputs the basic attributes of the Animal, such as its name
     * and lifespan.
     *
     * @param ostream The output stream where the Animal's details will be written.
     */
    virtual void Write(std::ostream& ostream);

    /**
     * @brief Retrieves the name of the animal.
     *
     * This method returns the name of the animal as a string.
     * The name is a private member of the Animal class set during object initialization.
     *
     * @return The name of the animal as a std::string.
     */
    std::string GetName() const { return name; }
    /**
     * @brief Retrieves the type of the animal.
     *
     * This method is a pure virtual function that must be implemented
     * in derived classes to return the specific type of the animal as
     * defined in the `Animal::eType` enumeration.
     *
     * @return The type of the animal as an `Animal::eType` value.
     */
    virtual eType GetType() = 0;

    /**
     * @brief Stores the name of the animal.
     *
     * This variable represents the name of the animal, typically assigned
     * during the creation of an object of the `Animal` class or its derived classes.
     * It is used to identify or describe the animal.
     */
protected:
    std::string name;
    /**
     * @brief Represents the average lifespan of an animal in years.
     *
     * This variable stores the expected lifespan of an animal. It is used to
     * define and represent the longevity of the animal in various contexts,
     * such as serialization, computing lifespan-related attributes, or
     * providing information about the animal to users.
     */
    int lifespan;
};

/**
 * Reads the details of an Animal object from the input stream and writes prompts to the output stream.
 * Prompts the user for the name and lifespan of the animal and updates the object accordingly.
 *
 * @param ostream The output stream to which prompts are written.
 * @param istream The input stream from which the data is read.
 */
inline void Animal::Read(std::ostream& ostream, std::istream& istream) {
    ostream << "Enter name: ";
    istream >> name;
    ostream << "Enter lifespan: ";
    istream >> lifespan;
}

/**
 * Writes the details of the Animal object to the provided output stream.
 * This includes the name and lifespan of the animal.
 *
 * @param ostream The output stream where the Animal object's details will be written.
 */
inline void Animal::Write(std::ostream& ostream) {
    ostream << "Name: " << name << "\n";
    ostream << "Lifespan: " << lifespan << " years\n";
}

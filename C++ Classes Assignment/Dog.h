#pragma once
#include "Animal.h"

/**
 * @class Dog
 * @brief Represents a Dog, which is a specific type of Animal.
 *
 * The Dog class inherits from the Animal base class and adds specific attributes and behaviors for dogs.
 * It includes the breed of the dog as a distinguishing feature.
 */
class Dog : public Animal {
    /**
     * Default constructor for the Dog class.
     * Initializes a Dog object with default values.
     *
     * @return A default-initialized Dog object.
     */
public:
    Dog() = default;

    /**
     * Constructs a Dog object with the specified name, lifespan, and breed.
     *
     * @param name The name of the dog.
     * @param lifespan The expected lifespan of the dog.
     * @param breed The breed of the dog.
     */
    Dog(const std::string& name, int lifespan, std::string breed)
        : Animal(name, lifespan), breed(breed) {}

    /**
     * Reads the attributes of the Dog object from the input stream and provides prompts via the output stream.
     * This method overrides the base class `Animal::Read` method to include reading the specific attribute `breed` of the Dog class.
     *
     * @param ostream An output stream used to prompt and provide messages to the user.
     * @param istream An input stream used to receive input from the user.
     */
    void Read(std::ostream& ostream, std::istream& istream) override;

    /**
     * Writes the details of the Dog object to the provided output stream.
     * This includes the details from the Animal class and additional information specific to the Dog class.
     *
     * @param ostream The output stream where the Dog object's details will be written.
     */
    void Write(std::ostream& ostream) override;

    /**
     * Retrieves the type of the animal.
     * Overrides the base class method to return the type specific to Dog.
     *
     * @return eType The enumerated type representing a Dog.
     */
    eType GetType() override { return eType::DOG; }
    /**
     * @variable breed
     * Represents the breed of the dog.
     * Stored as a string and used to identify the specific breed of a dog.
     */
private:
    std::string breed;
};

/**
 * Reads data for a Dog object, including its breed, from the given input stream.
 * Prompts are written to the provided output stream.
 * This method overrides the Read method of the Animal class and adds functionality specific to the Dog class.
 *
 * @param ostream The output stream to which prompts are written.
 * @param istream The input stream from which data for the Dog object is read.
 */
inline void Dog::Read(std::ostream& ostream, std::istream& istream) {
    Animal::Read(ostream, istream);
    ostream << "Enter breed: ";
    istream >> breed;
}

/**
 * Outputs the data of the Dog object to the given output stream.
 * This includes the data from the base class Animal and the breed of the dog.
 *
 * @param ostream The output stream to which the Dog object's data will be written.
 */
inline void Dog::Write(std::ostream& ostream) {
    Animal::Write(ostream);
    ostream << "Breed: " << breed << "\n";
}

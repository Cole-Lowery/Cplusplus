#pragma once
#include "Animal.h"

/**
 * @class Cat
 * @brief Represents a specific type of animal, the cat, which is derived from the Animal class.
 *
 * The Cat class extends the functionality of the Animal base class by adding attributes
 * specific to cats, such as whisker length. It also provides implementations for reading
 * and writing Cat-specific data as well as determining the animal type.
 */
class Cat : public Animal {
    /**
     * Default constructor for the Cat class.
     * Initializes a Cat object with default values.
     *
     * @return A default-initialized Cat object.
     */
public:
    Cat() = default;

    /**
     * Constructs a Cat object by initializing its name, lifespan, and whisker length.
     * Inherits name and lifespan properties from the Animal base class.
     *
     * @param name The name of the cat.
     * @param lifespan The average lifespan of the cat in years.
     * @param whiskerLength The length of the cat's whiskers in millimeters.
     * @return A constructed instance of the Cat class.
     */
    Cat(const std::string& name, int lifespan, int whiskerLength)
        : Animal(name, lifespan), whiskerLength(whiskerLength) {}

    /**
     * Reads the details of the Cat object from the input stream and writes prompts to the output stream.
     * This method asks for additional information specific to the Cat class, such as whisker length.
     * It also calls the Read method of the base Animal class to handle shared attributes.
     *
     * @param ostream The output stream to which prompts and messages are written.
     * @param istream The input stream from which the user provides the data.
     */
    void Read(std::ostream& ostream, std::istream& istream) override;

    /**
     * Outputs the details of the Cat object to the provided output stream.
     * This includes details from the base Animal class as well as Cat-specific information such as whisker length.
     *
     * @param ostream The output stream where the Cat's details will be written.
     */
    void Write(std::ostream& ostream) override;

    /**
     * Retrieves the type of the animal.
     *
     * @return The type of this animal as eType::CAT.
     */
    eType GetType() override { return eType::CAT; }
    /**
     * @brief Represents the length of a cat's whiskers in millimeters.
     *
     * This member variable is part of the `Cat` class and is used to store
     * the physical characteristic of a cat's whisker length.
     */
private:
    int whiskerLength;
};

/**
 * Reads the Cat-specific input fields from the provided input stream and writes prompts to the output stream.
 * This method first invokes the base class `Read` function to read common Animal fields,
 * then it prompts and reads the whisker length specific to the Cat.
 *
 * @param ostream The output stream used to write prompts for user input.
 * @param istream The input stream used to read user-provided data.
 */
inline void Cat::Read(std::ostream& ostream, std::istream& istream) {
    Animal::Read(ostream, istream);
    ostream << "Enter whisker length (in mm): ";
    istream >> whiskerLength;
}

/**
 * Writes the Cat-specific details to the provided output stream.
 * Calls the base class (Animal) Write method to include shared details,
 * then appends the cat's whisker length.
 *
 * @param ostream The output stream where the Cat details will be written.
 */
inline void Cat::Write(std::ostream& ostream) {
    Animal::Write(ostream);
    ostream << "Whisker Length: " << whiskerLength << " mm\n";
}

#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
    Dog() = default;
    Dog(const std::string& name, int lifespan, std::string breed)
        : Animal(name, lifespan), breed(breed) {}
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    eType GetType() override { return eType::DOG; }
private:
    std::string breed;
};
inline void Dog::Read(std::ostream& ostream, std::istream& istream) {
    Animal::Read(ostream, istream);
    ostream << "Enter breed: ";
    istream >> breed;
}
inline void Dog::Write(std::ostream& ostream) {
    Animal::Write(ostream);
    ostream << "Breed: " << breed << "\n";
}

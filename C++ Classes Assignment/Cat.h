#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
    Cat() = default;
    Cat(const std::string& name, int lifespan, int whiskerLength)
        : Animal(name, lifespan), whiskerLength(whiskerLength) {}
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    eType GetType() override { return eType::CAT; }
private:
    int whiskerLength;
};
inline void Cat::Read(std::ostream& ostream, std::istream& istream) {
    Animal::Read(ostream, istream);
    ostream << "Enter whisker length (in mm): ";
    istream >> whiskerLength;
}
inline void Cat::Write(std::ostream& ostream) {
    Animal::Write(ostream);
    ostream << "Whisker Length: " << whiskerLength << " mm\n";
}

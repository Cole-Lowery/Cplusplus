#pragma once
#include <string>
#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;

    enum class eType { CAT, DOG };

    Animal() = default;
    Animal(const std::string& name, int lifespan) : name(name), lifespan(lifespan) {}

    virtual void Read(std::ostream& ostream, std::istream& istream);
    virtual void Write(std::ostream& ostream);
    std::string GetName() const { return name; }
    virtual eType GetType() = 0;

protected:
    std::string name;
    int lifespan;
};

inline void Animal::Read(std::ostream& ostream, std::istream& istream) {
    ostream << "Enter name: ";
    istream >> name;
    ostream << "Enter lifespan: ";
    istream >> lifespan;
}

inline void Animal::Write(std::ostream& ostream) {
    ostream << "Name: " << name << "\n";
    ostream << "Lifespan: " << lifespan << " years\n";
}

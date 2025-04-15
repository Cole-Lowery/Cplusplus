#pragma once
#include <vector>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

class Database {
public:
    ~Database();
    void Create(Animal::eType type);
    void DisplayAll();
    void Display(const std::string& name);
    void Display(Animal::eType type);

private:
    std::vector<Animal*> objects;
};

inline Database::~Database() {
    for (Animal* obj : objects) {
        delete obj;
    }
}

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

inline void Database::DisplayAll() {
    for (Animal* obj : objects) {
        obj->Write(std::cout);
        std::cout << "-------------------\n";
    }
}

inline void Database::Display(const std::string& name) {
    for (Animal* obj : objects) {
        if (obj->GetName() == name) {
            obj->Write(std::cout);
            std::cout << "-------------------\n";
        }
    }
}

inline void Database::Display(Animal::eType type) {
    for (Animal* obj : objects) {
        if (obj->GetType() == type) {
            obj->Write(std::cout);
            std::cout << "-------------------\n";
        }
    }
}

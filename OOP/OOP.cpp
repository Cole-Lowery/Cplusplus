#include <iostream>
#include "Human.h"

int main()
{
    {
        Human human;
        Human human1;
        Human human2;
        Human human3;
        std::cout << Human::GetCount() << std::endl;
    }
    std::cout << Human::GetCount() << std::endl;
}
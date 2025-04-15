#include <iostream>
class Human
{
public:
    Human() {
        std::cout << "construction\n";
    }
    Human(const std::string &name, unsigned short age)
    {
        m_count++;
        m_name = name;
        m_age = age;
        std::cout << "construction\n";
    }
    ~Human() {
        std::cout << "destruction\n";
        m_count--;
    }
    static int GetCount() {return m_count;}
    std::string GetName(){return m_name;}
    unsigned short GetAge(){return m_age;}
private:

    std::string m_name;
    unsigned short m_age = 0;
    static int m_count;
    static float tax;
};

#include <iostream>
using namespace std;

struct Person
{
    char name[32];
    int id;
};

// ** REFERENCE PARAMETER **
void Square(int& i)
{
    i = i * i;
}

// ** POINTER PARAMETER **
void Double(int* i)
{
    *i = *i * 2;
}

int main()
{
    // ** REFERENCE **
    int num = 5; // declare an int variable and set the value to some number (less than 10)
    int& ref = num; // declare an int reference and set it to the int variable above
    cout << "Initial value of num: " << num << endl; // output the int variable
    ref = 7; // set the int reference to some number
    cout << "Value of num after changing reference: " << num << endl; // output the int variable
    // what happened to the int variable when the reference was changed? (insert answer)
    // Answer: The int variable's value changed because the reference directly modifies the original variable.
    cout << "Address of num: " << &num << endl; // output the address of the int variable
    cout << "Address of ref: " << &ref << endl; // output the address of the int reference
    // are the addresses the same or different? (insert answer)
    // Answer: The addresses are the same because the reference is an alias for the variable.

    // ** REFERENCE PARAMETER **
    Square(num); // call the Square function with the int variable created in the REFERENCE section
    cout << "Value of num after calling Square: " << num << endl; // output the int variable to the console

    // ** POINTER VARIABLE **
    int* ptr = nullptr; // declare an int pointer, set it to nullptr (it points to nothing)
    ptr = &num; // set the int pointer to the address of the int variable created in the REFERENCE section
    cout << "Value of pointer (address it points to): " << ptr << endl; // output the value of the pointer
    // what is this address that the pointer is pointing to? (insert answer)
    // Answer: The address is the memory location of the variable 'num'.
    cout << "Value of the object the pointer is pointing to: " << *ptr << endl; // output the value of the object the pointer is pointing to (dereference the pointer)

    // ** POINTER PARAMETER **
    Double(ptr); // call the Double function with the pointer created in the POINTER VARIABLE section
    cout << "Value of num after calling Double: " << *ptr << endl; // output the dereference pointer
    cout << "Value of num after calling Double: " << num << endl; // output the int variable created in the REFERENCE section
    // did the int variable's value change when using the pointer?
    // Answer: Yes, the int variable's value changed because the pointer directly modifies the original variable.

    return 0;
}


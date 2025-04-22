#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    std::cout << "Hello World!\n";
    static_assert(1 == 1, "1 == 1");
    std::cout << "Assertion passed!\n";
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << endl;
    int randomNumber = rand() % 10 + 1;
    cout << "Random number: " << randomNumber << endl;
    return 0;
}
#include "Cat.h"
#include <iostream>
using namespace std;
//4 case constructor list to capture most situations where not all information is provided. 
Cat::Cat() : itsAge(0), itsWeight(0), itsName("Nameless") {}
Cat::Cat(int age) : itsAge(age), itsWeight(0), itsName("Nameless") {}
Cat::Cat(int age, int weight) : itsAge(age), itsWeight(weight), itsName("Nameless") {}
Cat::Cat(int age, int weight, std::string name) : itsAge(age), itsWeight(weight), itsName(name) {}

void Cat::meow(int itsName) const {
cout << itsName << " says meow!" << endl;
}

int Cat::GetAge() const {
    return itsAge;
}

int Cat::GetWeight() const {
    return itsWeight;
}

std::string Cat::getName() const {
    return itsName;
}
//checks to make sure age is set to a positive value greater than 0, and if so it sets the age and returns the value.
int Cat::SetAge(int age) {
    if (age <= 0) {
        cout << "Age Error" << endl;
        return itsAge;
    }
    itsAge = age;
    return itsAge;
}

int Cat::SetWeight(int weight) {
    if (weight <= 0) {
        cout << "Weight Error" << endl;
        return itsWeight;
    }
    itsWeight = weight;
    return itsWeight;
}

std::string Cat::setName(std::string name) {
    if (name.empty()) {
        cout << "Name Error" << endl;
        return itsName;
    }
    itsName = name;
    return itsName;
}
//displayInfo prints the name, age, and weight of the cat each on one line before indenting the end to allow for readability
// when multiple cats are being evaluated.
void Cat::displayInfo() const {
    cout << "Cat: " << itsName << endl;
    cout << "Age: " << itsAge << endl;
    cout << "Weight: " << itsWeight << endl;
    cout << endl;
}
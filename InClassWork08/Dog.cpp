#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <string>
using namespace std;
class Dog
{
private:
string name;
string breed;
int age;
const static double licenseFee;
public:
void setName(string n) {
    name = n;
}
void setBreed(string b) {
    breed = b;
}
void setAge(int a) {
    age = a;   
}
void display() {
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
    cout << "Age: " << age << endl;
    cout << "License Fee: $" << licenseFee << endl;
}
};
#endif // DOG_H
const double Dog::licenseFee = 12.25;
int main() {
Dog Dog1;
Dog1.setName("Jame");
Dog1.setBreed("Shiba");
Dog1.setAge(3);
Dog1.display();
return 0;
}

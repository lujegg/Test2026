#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Character
{
private:
int color;
int eyes;
int legs; // assuming you meant legs, not lives
public:
void setColor() {
    color = rand() % 100 + 1;
}
void setEyes() {
    eyes = rand() % 10 + 1;
}
void setLegs() {
    legs = rand() % 12 + 1;
}
void getColor() {
    cout << "Color: " << color << endl;
}
void getEyes() {
    cout << "Eyes: " << eyes << endl;
}
void getLegs() {
    cout << "Legs: " << legs << endl;
}
void display() {
    getColor();
    getEyes();
    getLegs();
}
};
#endif // CHARACTER_H
int main() {
    Character John;
    Character Jane;
    John.setColor();
    John.setEyes();
    John.setLegs();
    Jane.setColor();
    Jane.setEyes();
    Jane.setLegs();
    cout << "John's Character:" << endl;
    John.display();
    cout << "Jane's Character:" << endl;
    Jane.display();
return 0;
}

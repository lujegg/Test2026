#include "Square.h"
#include <iostream>
using namespace std;
//checks to make sure side is not 0 or negative, and then sets the private value side equal to s.
Square::Square(int s) {
    if (s <= 0) {
        cout << "Side Error" << endl;
        return;
    }
    side = s;
}
void Square::setSide(int s) {
    if (s <= 0) {
        //checks to make sure that the side length is not 0 or negative
        cout << "Side Error" << endl;
        return;
    }
    side = s;
}
int Square::getSide() const {
    return side;
}
int Square::getArea() const {
    return side * side;
}
int Square::getPerimeter() const {
    return 4 * side;
}
#ifndef SQUARE_H

#define SQUARE_H
//original
//class Square
//{
//public:
//    int side;
//};
//requires a ; after } for class declaration
class Square
{
private:
    int side;
public:
    Square(int s);
    void setSide(int s);
    int getSide() const;
    int getArea() const;
    int getPerimeter() const;
};
#endif // SQUARE_H
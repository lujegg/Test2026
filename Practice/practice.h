#ifndef PRACTICE_H
#define PRACTICE_H
#include "string"
//create a apple program, featuring apple #, color, and size(diameter in cm)
class apple 
{
private:
int numapple;
std::string colapple;
double sizeapple;
public:
apple();
apple(int num, std::string col, double size);
int setnumapples(int num);
int getnumapples();
std::string setcolapples(std::string col);
std::string getcolapples();
double setsizeapples(double size);
double getsizeapples();
};
#endif // PRACTICE_H

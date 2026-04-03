//original
//class Cat
//{
//    int GetAge() const;
//private:
//    int itsAge;
//};
//this isn't very useful as by default undeclared functions are declared as private, and therefore you cannot call upon getAge from outside

#include "string"
#ifndef CAT_H

#define CAT_H
class Cat
{
public:
    Cat();
    Cat(int age);
    Cat(int age, int weight);
    Cat(int age, int weight, std::string name);
    void meow(int name) const;
    int GetAge() const;
    int GetWeight() const;
    std::string getName() const;
    int SetAge(int age);
    int SetWeight(int weight);
    std::string setName(std::string name);
    void displayInfo() const;
private:
    int itsAge;
    int itsWeight;
    std::string itsName;
};
#endif // CAT_H
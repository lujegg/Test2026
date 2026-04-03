#include "Employee.h"
#include <iostream>
using namespace std;
//Constructor chain that initializes the values for different situations, setting values equal to 0 when not provided.
Employee::Employee() {
    setnum(0);
    setAge(0);
    setYearsOfService(0);
    setSalary(0);
}
Employee::Employee(int num, int age, int salary) {
    setnum(num);
    setAge(age);
    setYearsOfService(0);
    setSalary(salary);
}

int Employee::getAge() const {
    return itsAge;
}
int Employee::getYearsOfService() const {
    return itsYearsOfService;
}
double Employee::getSalary() const {
    return itsSalary;
}
int Employee::getnum() const {
    return itsNum;
}
//Validation to ensure age is not 0 or negative
void Employee::setAge(int age) {
    if (age <= 0) {
        cout << "Age Error" << endl;
        return;
    }
    itsAge = age;
}
//Validation to ensure years of service is not negative
void Employee::setYearsOfService(int years) {
    if (years < 0) {
        cout << "Years of Service Error" << endl;
        return;
    }
    itsYearsOfService = years;
}
//Validation to ensure salary is not 0 or negative
void Employee::setSalary(int salary) {
    if (salary <= 0) {
        cout << "Salary Error" << endl;
        return;
    }
    itsSalary = salary;
}
//Validation to ensure number is not 0 or negative
void Employee::setnum(int num) {
    if (num <= 0) {
        cout << "Employee Number Error" << endl;
        return;
    }
    itsNum = num;
}
void Employee::display() {
    cout << "Employee: " << itsNum << endl;
    cout << "Age: " << itsAge << endl;
    cout << "Years of Service: " << itsYearsOfService << endl;
    cout << "Salary: $" << itsSalary << endl;
    cout << endl;
}
//As int automatically truncates remainders, adding 500 results in salaries ending in 500 or more being rounded up, and if not then the value
//truncated as normal. 
int Employee::getSalaryInThousands() const {
    return (itsSalary + 500) / 1000;
}
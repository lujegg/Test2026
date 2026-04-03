#include <iostream>
#include "Employee.h"
// t
using namespace std;
int main() {
    Employee emp;
    emp.setnum(1);
    emp.setAge(30);
    emp.setYearsOfService(5);
    emp.setSalary(75000.0);
    emp.display();
    cout << emp.getSalaryInThousands() << endl;
    //cout << "Employee 1:" << endl;
    //cout << "Age: " << emp.getAge() << endl;
    //cout << "Years of Service: " << emp.getYearsOfService() << endl;
    //cout << "Salary: $" << emp.getSalary() << endl;
    Employee emp2;
    emp2.setnum(2);
    emp2.setAge(40);
    emp2.setYearsOfService(15);
    emp2.setSalary(95500.0);
    emp2.display();
    cout << emp2.getSalaryInThousands() << endl;
    //cout << "Employee 2:" << endl;
    //cout << "Age: " << emp2.getAge() << endl;
    //cout << "Years of Service: " << emp2.getYearsOfService() << endl;
    //cout << "Salary: $" << emp2.getSalary() << endl;
}
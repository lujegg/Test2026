#ifndef EMPLOYEE_H

#define EMPLOYEE_H
class Employee {
private:
int itsAge;
int itsYearsOfService;
int itsSalary;
int itsNum;
public:
Employee();
Employee(int num, int age, int salary);
void display();
int getAge() const;
int getYearsOfService() const;
double getSalary() const;
int getnum() const;
void setnum(int num);
void setAge(int age);
void setYearsOfService(int years);
void setSalary(int salary);
int getSalaryInThousands() const;
};
#endif // EMPLOYEE_H
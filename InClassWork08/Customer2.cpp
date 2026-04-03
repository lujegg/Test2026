#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;
class Customer
{
private:
int IDnum;
string FirstName;
string LastName;
int CreditLim;
public:
void setIDnum() {
    cout << "Enter Customer ID: "; 
    cin >> IDnum;
    IDnum;
}
void setFirstName() {
    cout << "Enter First Name: ";
    cin >> FirstName;
    FirstName;
}
void setLastName() {
    cout << "Enter Last Name: ";
    cin >> LastName;
    LastName;
}
void setCreditLim() {
    cout << "Enter Credit Limit: ";
    cin >> CreditLim;
    if (CreditLim > 10000) {
        cout << "Limit Error" << endl;
        return;
    }
}
void display() {
    cout << "Customer ID: " << IDnum << endl;
    cout << "Name: " << FirstName << " " << LastName << endl;
    cout << "Credit Limit: $" << CreditLim << endl;
}
};
#endif // CUSTOMER_H

int main() {
const int count = 5;
Customer Customers[count];
for (int i = 0; i < count; i++) {
    cout << "Customer " << (i + 1) << ":" << endl;
    Customers[i].setIDnum();
    Customers[i].setFirstName();
    Customers[i].setLastName();
    Customers[i].setCreditLim();
    cout << endl;
}
for (int i = 0; i < count; i++) {
    cout << "Customer " << (i + 1) << ":" << endl;
    Customers[i].display();
    cout << endl;
}
return 0;
}

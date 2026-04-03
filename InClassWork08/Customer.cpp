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
void setIDnum(int id) {
    IDnum = id;
}
void setFirstName(string first) {
    FirstName = first;
}
void setLastName(string last) {
    LastName = last;
}
void setCreditLim(int lim) {
    if (lim > 10000) {
        cout << "Limit Error" << endl;
        return;
    }
    CreditLim = lim;
}
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
Customer myCustomer;
myCustomer.setIDnum(12345);
myCustomer.setFirstName("Jack");
myCustomer.setLastName("Lu");
myCustomer.setCreditLim(5000);
myCustomer.display();
return 0;
}

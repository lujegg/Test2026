#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
using namespace std;
class Order
{
private:
static double TableCharge;
int TableNum;
string ServerName;
int NumGuests;
public:
static void getTableCharge() {
    cout << "Table Charge: $" << TableCharge << endl;
}
void setTableNum(int num) {
    TableNum = num;
}
void setServerName(string name) {
    ServerName = name;
}
void setNumGuests(int num) {
    NumGuests = num;
}
};
#endif // ORDER_H
double Order::TableCharge = 4.75;
int main() {
    Order::getTableCharge();
    return 0;
}

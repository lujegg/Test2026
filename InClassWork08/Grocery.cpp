#ifndef GROCERY_H
#define GROCERY_H
#include <iostream>
#include <string>
using namespace std;
class Grocery
{
private:
int StockNum;
double Price;
int Quantity;
double Value;
void setStockNum() {
    do {
        cout << "Enter Stock Number from 1000 to 9999: ";
        cin >> StockNum;
        if (StockNum < 1000 || StockNum > 9999) {
            cout << "Invalid." << endl;
        }
    } while (StockNum < 1000 || StockNum > 9999);
}
void setPrice() {
    do {
        cout << "Enter Price: ";
        cin >> Price;
        if (Price < 0) {
            cout << "Price Error" << endl;
        }
    } while (Price < 0);
}
void setQuantity() {
    do {
        cout << "Enter Quantity: ";
        cin >> Quantity;
        if (Quantity < 0) {
            cout << "Quantity Error" << endl;
        }
    } while (Quantity < 0);
}
void setValue() {
    Value = Price * Quantity;
}
public:
void DataEntry() {
    setStockNum();
    setPrice();
    setQuantity();
    setValue();
}
void display() {
    cout << "Stock Number: " << StockNum << endl;
    cout << "Price: $" << Price << endl;
    cout << "Quantity: " << Quantity << endl;
    cout << "Value: $" << Value << endl;
}
};
#endif // GROCERY_H

int main() {
Grocery GroceryItem;
GroceryItem.DataEntry();
GroceryItem.display();
return 0;
}

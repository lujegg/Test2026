#include "Publication.h"
#include <iostream>
using namespace std;

double calculateCost(int pages, double discountPercent)
{
    if (pages <= 0 || discountPercent < 0 || discountPercent > 50)
    {
        return -1;
    }
    double cost = calculateCost(pages) * (1 - (discountPercent / 100));
    return cost;
}
double calculateCost(int pages)
{
    if (pages <= 0)
    {
        return -1;
    }
    double cost = pages * 0.05;
    return cost;
}
double calculateCost(int pages, bool hardcover)
{
    if (pages <= 0)
    {
        return -1;
    }
    if (hardcover == 0)
    {
        return calculateCost(pages);
    }

    double cost = (pages * 0.05) + 7.5;
    return cost;
    
}
double calculateCost(int pages, bool hardcover, int colorPages)
{
    if (pages <= 0)
    {
        return -1;
    }
    if (colorPages < 0 || colorPages > pages)
    {
        return -1;
    }
    if (hardcover == false && colorPages == 0)
    {
        return calculateCost(pages);
    }
    if (hardcover == true && colorPages == 0)
    {
        return calculateCost(pages, hardcover);
    }
    if (hardcover == false && colorPages > 0)
    {
        double cost = calculateCost(pages) + (colorPages * 0.2);
        return cost;
    }

        double cost = calculateCost(pages, hardcover) + (colorPages * 0.2);
        return cost;
}
void printReceipt(int pages, bool hardcover, int colorPages, double cost)
{
    if (pages <= 0 || colorPages < 0 || colorPages > pages || cost < 0)
        {
            cout << "Can't print receipt" << endl;
            return;
        }
        cout << "Pages: " << pages << endl;
        cout << "Hardcover: " << (hardcover ? "Yes" : "No") << endl;
        cout << "Color Pages: " << colorPages << endl;
        cout << "Total Cost: $" << cost << endl;
}
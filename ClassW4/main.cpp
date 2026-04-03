#include <iostream>
#include "Publication.h"
// t
using namespace std;
int main()
{
    int option = 0;
    int x = 0;
    while (option != 4)
    {
    int pages = 0;
    bool hardcover = 0;
    int colorPages = 0;
    double cost = 0;
    double discountPercent = 0.0;
    cout<<"------------------------------"<<endl;
    cout<< "Enter number corresponding to option"<<endl;
    cout<< "1. Cost by pages only"<<endl;
    cout<< "5. Discounted pages only"<<endl;
    cout<< "2. Cost by pages and hardcover"<<endl;
    cout<< "3. Cost by pages and hardcover and color pages"<<endl;
    cout<< "4. Exit"<<endl;
    cin>>option;
    if (option == 1)
    {
        cout<<"Enter number of pages: ";
        cin>>pages;
        cost = calculateCost(pages);
        cout<<"Cost: "<<cost<<endl;
    }
    if (option == 2)
    {
        cout<<"Enter number of pages: ";
        cin>>pages;
        cout<<"Enter hardcover (1 is yes, 0 is no): ";
        cin>>x;
        if (x != 0 && x != 1)
        {
            cout<<"error"<<endl;
            continue;
        }
        hardcover = x;
        cost = calculateCost(pages, hardcover);
        cout<<"Cost: "<<cost<<endl;
    }
    if (option == 3)
    {
        cout<<"Enter number of pages: ";
        cin>>pages;
        cout<<"Enter hardcover (1 is yes, 0 is no): ";
        cin>>x;
        if (x != 0 && x != 1)
        {
            cout<<"error"<<endl;
            continue;
        }
        hardcover = x;
        cout<<"Enter number of color pages: ";
        cin>>colorPages;
        cost = calculateCost(pages, hardcover, colorPages);
        cout<<"Cost: "<<cost<<endl;
        
    }
    if (option == 5)
    {
        cout<<"Enter number of pages: ";
        cin>>pages;
        cout<<"Enter discount percent: ";
        cin>>discountPercent;
        discountPercent = discountPercent / 1.0;
        cost = calculateCost(pages, discountPercent);
        cout<<"Cost: "<<cost<<endl;
    }
    if (option == 4)
    {
        return 0;
    }
    printReceipt(pages, hardcover, colorPages, cost);
}
}
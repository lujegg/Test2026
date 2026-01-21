#include <iostream>
using namespace std;

double area(double width, double height)
{
    return width * height;
}

int main()
{
    double w, h;
    cout << "Enter width: ";
    cin >> w;
    cout << "Enter height: ";
    cin >> h;
    
    cout << "Area = " << area(w, h) << endl;
    return 0;
}
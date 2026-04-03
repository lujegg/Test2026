#include <iostream>
#include <cmath>
using namespace std;
//===========function definition
    bool comparison(double x,double y,double z) {
    return (floor(x*y) == floor(z));
    }
//===========check
int main()
{
    double x;
    double y;
    double z;
    cout<<"Enter first number: ";
    cin>>x;
    cout<<"Enter second number: ";
    cin>>y;
    cout<<"Enter third number: ";
    cin>>z;
    cout<<comparison(x,y,z)<<endl;
}    
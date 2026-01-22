//calculator
#include <iostream>

using namespace std;

int main()
{
    char stuff;
    int num1;
    int num2;
    int ans;
    cout<<"Enter your operator(+,-,*,/)"<<endl;
    cin>>stuff;
    cout<<"Enter your first number"<<endl;
    cin>>num1;
    cout<<"Enter your second number"<<endl;
    cin>>num2;
        if ( stuff == '*' )
        {
            ans = num1*num2;
        }
        if ( stuff == '/' && num2 != 0 )
        {
            ans = num1/num2;
        }
        if ( stuff == '+' )
        {
            ans = num1+num2;
        }
        if ( stuff == '-' )
        {
            ans = num1-num2;
        }
        
    cout<<"Your answer: "<<ans<<endl;
}

//Calc
#include <iostream>

using namespace std;
int main()
{
    char x;
    char stuff;
    int num1;
    int num2;
    int ans;
    cout<<"Do you want to do calculations?(y/n)"<<endl;
    cin>>x;
    if ( x == 'n' || x == 'N')
    {
        return 0;
    }
    while ( x == 'y' || x == 'Y' )
    {

    cout<<"Enter your operator(+,-,*,/)"<<endl;
    cin>>stuff;
    cout<<"Enter your first number"<<endl;
    cin>>num1;
    cout<<"Enter your second number"<<endl;
    cin>>num2;
        if ( stuff == '*' )
        {
            ans = num1*num2;
            cout<<"Your answer: "<<ans<<endl;
        }
        if ( stuff == '+' )
        {
            ans = num1+num2;
            cout<<"Your answer: "<<ans<<endl;
        }
        if ( stuff == '-' )
        {
            ans = num1-num2;
            cout<<"Your answer: "<<ans<<endl;
        }
        if ( stuff == '/' && num2 != 0 )
        {
            ans = num1/num2;
        cout<<"Your answer: "<<ans<<endl;}
        if ( stuff == '/' && num2 == 0 )
        {
            cout<<"Error"<<endl;}
        cout<<"Do you want to do calculations?(y/n)"<<endl;
        cin>>x;
    }
}


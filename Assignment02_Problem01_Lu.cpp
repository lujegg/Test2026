#include <iostream>
using namespace std;
//work

int main()
{
    int n;
    string name;
    int i;
    
    cout<<"How many numbers are in the secret sequence?"<<endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int code;
        cout<<"Enter a code "<<i+1<<": ";
        cin >> code;
    }
    cout<<"numbers"<<code<<endl;
    return 0;
}

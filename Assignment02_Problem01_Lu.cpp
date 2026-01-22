#include <iostream>
using namespace std;
//work

int main()
{
    int n;
    int i;
    
    cout<<"How many numbers are in the secret sequence?"<<endl;
    cin >> n;

        if (n <= 0){
            cout<<"error"<<endl;
            return 0;
    }
    int code[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter a code "<<i+1<<": ";
        cin >> code[i];
        if (1<=code[i] && code[i]<=26)
            continue;
        else
            cout<<"?"<<endl;
            return 0;
    }
    for(int i=0; i<n; i++){
        if (code[i] == 1) {cout << "A";}
        if (code[i] == 2) {cout << "B";}
        if (code[i] == 3) {cout << "C";}
        if (code[i] == 4) {cout << "D";}
        if (code[i] == 5) {cout << "E";}
        if (code[i] == 6) {cout << "F";}
        if (code[i] == 7) {cout << "G";}
        if (code[i] == 8) {cout << "H";}
        if (code[i] == 9) {cout << "I";}
        if (code[i] == 10) {cout << "J";}
        if (code[i] == 11) {cout << "K";}
        if (code[i] == 12) {cout << "L";}
        if (code[i] == 13) {cout << "M";}
        if (code[i] == 14) {cout << "N";}
        if (code[i] == 15) {cout << "O";}
        if (code[i] == 25) {cout << "P";}
        if (code[i] == 16) {cout << "Q";}
        if (code[i] == 17) {cout << "R";}
        if (code[i] == 18) {cout << "S";}
        if (code[i] == 19) {cout << "T";}
        if (code[i] == 20) {cout << "U";}
        if (code[i] == 21) {cout << "V";}
        if (code[i] == 22) {cout << "W";}
        if (code[i] == 23) {cout << "X";}
        if (code[i] == 24) {cout << "Y";}
        if (code[i] == 25) {cout << "Z";}
    }
    return 0;
}

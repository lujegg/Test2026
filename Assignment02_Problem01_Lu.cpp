//secret
#include <iostream>
using namespace std;

int main()
{
    int n;
    int i;
    int x;
    int y;
    int h;
    while (h != 0 && h != 1 && h != 2){
        cout<< "What do you want to do?"<<endl;
        cout<< "Enter 0 to Exit"<<endl;
        cout<< "Enter 1 for Decode"<<endl;
        cout<< "Enter 2 to Explain secret code conversion"<<endl;
        cin >> h;
    switch (h)
    {
        case 1:
            break;
        case 2:
            cout<< "The secret code is decoded by converting numbers 1 to 26 into their alphabetical equivalents such as A,B,C...Z. A corresponds to 1, B to 2, C to 3 and on until Z. If a number outside the range of 1-26 is entered, an error message ? will be printed." <<endl;
            return 0;
        case 0:
            return 0;
        default:
            cout<<"Invalid"<<endl;
    }
    }
    y = 0;
    cout<<"How many secret codes do you want to decode?"<<endl;
    cin >> x;
    do {
        cout<<"How many numbers are in the secret sequence?"<<endl;
        cin >> n;

            while (n <= 0){
                cout<<"error"<<endl;
                cout<<"How many numbers are in the secret sequence?"<<endl;
                cin >> n;
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
        cout << "Your code is ";
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
        cout<< " "<<endl;
        y++;
    } while (x > y );
    return 0;
}

//original
//class TV
//{
//public:
//void SetStation ( int Station ) ;
//int GetStation () const ;
//private:
//int itsStation ;
//};

//int main ()
//{
//TV myTV ;
//myTV.itsStation = 9;
//TV.SetStation (10) ;
//TV myOtherTV (2) ;
//}
// Bug 1: Trying to set private int itsStation from main
// Bug 2: TV.setStation(10) calls on the class name rather than the object
// Bug 3: TV myOtherTV(2) tries to create a new object called myOtherTV using parameter 2, however there is no constructor that allows for it
// to use parameters when creating a new object.
#include "TV.h"
#include <iostream>
using namespace std;

TV::TV() : itsStation(1) {}
TV::TV(int station) : itsStation(station) {}
//Validates that station is between 1 and 999 by verifying that its not less than 1 nor greater than 999.
void TV::SetStation(int station) {
    if (station < 1 || station > 999) {
        cout << "Station Error" << endl;
        return;
    }
    itsStation = station;
}
int TV::GetStation() const {
    return itsStation;
}
int TV::displayStatus() const {
    cout << "Channel " << itsStation << endl;
    return itsStation;
}
//Upon requesting channelUp when itsStation value is 999, it automatically sets it to 1 in a sort of rotating channel manner, similar to
//how the radio had worked in the past. ChannelDown follows the same idea, but in the opposite direction.
void TV::channelUp() {
    if (itsStation == 999) {
        itsStation = 1;
    } else {
        itsStation++;
    }
}
void TV::channelDown() {
    if (itsStation == 1) {  
        itsStation = 999;
    } else {
        itsStation--;
    }
}  
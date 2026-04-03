#include "TV.h"
#include <iostream>

using namespace std;
int main()
{
TV myTV;
//While myTV has the initial value of 1, the following line sets the station to 9 and then does channelUp after display.
myTV.SetStation(9);
myTV.displayStatus();
myTV.channelUp();
TV myOtherTV(2);
myTV.displayStatus();
myOtherTV.displayStatus();
}
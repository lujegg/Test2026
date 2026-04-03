#ifndef DIE_H
#define DIE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Die
{
private:
    int DieValue;
    static const int MaxValue = 6;
    int TotalValue;
public:
Die() : DieValue(0), TotalValue(0) {}

void setDieValue(int value) {
    if (value < 1 || value > MaxValue) {
        cout << "Value Error" << endl;
        return;
    }
    DieValue = value;
}
void getDieValue() {
    cout << "Die Value: " << DieValue << endl;
}
int getTotalValue() {
    return TotalValue;
}
void rollDie() {
    DieValue = rand() % MaxValue + 1;
    TotalValue += DieValue;
}

};
#endif // DIE_H
int main() {
srand(static_cast<unsigned int>(time(0)));
bool HitPlayer = true;
bool HitComputer = true;
Die Player;
Die Computer;
while (HitPlayer == true || HitComputer == true) {
    if (HitPlayer == true) {
        Player.rollDie();
        cout << "Player rolled: ";
    Player.getDieValue();
    }
    if (Computer.getTotalValue() < 19) {
        HitComputer = true;
    } else {
        HitComputer = false;
    }
    if (HitComputer == true) {
        Computer.rollDie();
        cout << "Computer rolled: ";
        Computer.getDieValue();
    }
cout << "Player Total: " << Player.getTotalValue() << endl;
if (Player.getTotalValue() > 21) {
    HitPlayer = false;
    break;
}
cout << "Computer Total: " << Computer.getTotalValue() << endl;
if (Computer.getTotalValue() > 21) {
    HitComputer = false;
    break;
}
if (HitPlayer == true) {
cout << "Continue? (1 for yes, 0 for no): ";
cin >> HitPlayer;
}
}
if (Player.getTotalValue() > 21) {
    cout << "Player Loses" << endl;
    return 0;
}
if (Computer.getTotalValue() > 21) {
    cout << "Computer Loses" << endl;
    return 0;
}
if (Player.getTotalValue() >= Computer.getTotalValue()) {
    cout << "Player Wins" << endl;
} else {
    cout << "Computer Wins" << endl;
}
return 0;
}
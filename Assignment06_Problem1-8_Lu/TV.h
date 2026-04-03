#ifndef TV_H

#define TV_H
class TV
{
public:
TV();
TV(int station);
void SetStation (int station);
int GetStation() const;
int displayStatus() const;
void channelUp();
void channelDown();
private:
int itsStation;
};
#endif // TV_H
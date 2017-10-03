#include <iostream>
using namespace std;

class Ship
{
 protected:
  int x , y, length, direction;
 public:
  Ship(x,y,l,d);
  void MakeAnyShip(int size,int direction,int shipx,int shipy,bool player);
};

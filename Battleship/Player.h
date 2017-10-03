#ifndef Player_h
#define Player_h
#include <iostream>
using namespace std;
int const D=10;

class Player
{
  friend class Game;
 protected:
  bool ship[D][D],hit[D][D];
  bool person;
  int startx,starty;
 public:
  Player();
  ~Player();
  void display();
  bool placeShip(int size,int direction, bool who, int shipx,int shipy);
};
#endif

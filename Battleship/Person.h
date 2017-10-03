#ifndef Person_h
#define Person_h
#include "Player.h"
using namespace std;

class Person:public Player
{
  friend class Game;
 public:
  void ShowShot(int x,int y,int xi,int yi);
  void PlaceAll();
  void start();
  Person():Player(){aimx=0;aimy=0;person=true;};
 protected:
  int aimx,aimy;
  void PlaceShip(int size);
  void ShowShip(int x,int y,int d,int s);
};
#endif

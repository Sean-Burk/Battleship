#ifndef Game_h
#define Game_h
#include <iostream>
#include "Ai.h"
using namespace std;
class Game
{
 protected:
  int row,col;
  void PlaceHim(int size);
  void MyTurn();
  void hisTurn();
 public:
  bool victory,defeat;
  Game();
  void printAll();
  bool shoot(int x,int y,bool who);
  bool fullTurn();
  Person me;
  Ai him;
};

#endif

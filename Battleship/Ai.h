#ifndef Ai_h
#define Ai_h
#include <vector>
#include "Player.h"

using namespace std;
struct cord{int x,y,d;};
class Ai:public Player
{
 public:
  void TakeTurn(bool meship[][10],bool mehit[][10]);
  Ai():Player(){state=0;};
 protected:
  int state,direction,;
  vector<cord> targets;
  int Neutral(bool meship[][10],bool mehit[][10]);
  int FoundND(bool meship[][10],bool mehit[][10]);
};


#endif

#include "Ship.h"

bool Ship::MakeAnyShip(int size,int direct, int shipx,int shipy,bool player)
{
  int starty,startx;
  getmaxyx(stdscr,starty,startx);
  startx=(startx-20)/2;
  if(who)
    starty=starty/4;
  else
    starty=starty*(3/4);
  if(direct==0)// not done also remove this function from Player.C/h
    {
      if(shipy-size<-1)
        return false;
    }
  else if(direct==1)
    {
      if(shipx+size>10)
        return false;
    }
  else if(direct==2)
    {
      if(shipy+size>10)
        return false;
    }
  else if(direct==3)
    if(shipx-size<-1)
      return false;
  length=size;
  direction=direct;
  if(player)
    {
      x=;
      y=;
      return true;
    }
  x=;
  y=;
  return true;
}

#include <iostream>
#include <ncurses.h>
#include "Ai.h"
#include<cstdlib>

int Ai::Neutral(bool meship[][10],bool mehit[][10])
{
  int x,y;
  bool done=false;
  do{
    x=rand()%10;
    y=rand()%10;
    if(mehit[x][y]==false)
      done=true;
  }while(!done);
  mehit[x][y]=true;
  if(meship[x][y]==true)
    {
      cord temp;
      temp.x=x;
      temp.y=y;
      temp.d=rand()%4;
      targets.push_back(temp);
      return 1;
    }
  return 0;
}

void Ai::TakeTurn(bool meship[][10],bool mehit[][10])
{
  switch(state)
    {
    case 0:state=Neutral(meship,mehit);
      break;
    case 1:mvprintw(0,0,"taking pathe one");
      getch();
      state=FoundND(meship,mehit);
      break;
    case 99:mvprintw(0,0,"There was an Ai error");
      getch();
      state=Neutral(meship,mehit);
      break;
    }
  return;
}

int Ai::FoundND(bool meship[][10],bool mehit[][10])
{
  int count=0,x,y;
  cord target=targets.back();
  targets.pop_back();
  do{
    target.d=(1+target.d)%4;
    int ix,iy;
    switch(target.d)
      {
      case 0:ix=0; iy=-1;
	break;
      case 1:ix=1; iy=0;
	break;
      case 2:ix=0; iy=1;
	break;
      case 3:ix=-1; iy=0;
	break;
      }
    x=target.x+ix;
    y=target.y+iy;
    count++;
    if(count>=4)
      {
	mvprintw(0,0,"Fucking cunt");
	getch();
	return Neutral(meship,mehit);
      }
  }while(mehit[x][y]);
  mehit[x][y]=true;
  if(meship[x][y]==true)
    return 1;
  return 1;
}

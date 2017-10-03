#include<iostream>
#include <ncurses.h>
#include<cstdlib>
//#include "Player.h"
#include "Person.h"
#include "Ai.h"
#include "Game.h"

Game::Game()
{
  victory=false;
  defeat=false;
  getmaxyx(stdscr,row,col);
  me.startx=(col)/2-10;
  me.starty=(3*row)/4-9;
  him.startx=(col)/2-10;
  him.starty=(row)/4;
  for(int i=2;i<=5;i++)
    PlaceHim(i);
  PlaceHim(3);
 }

bool Game::shoot(int x, int y,bool who)
{
  if(x>9||x<0||y>9||y<0)
    return false;
  if(who)
    {
      if(him.hit[x][y]==true)
	return false;
      him.hit[x][y]=true;
      return true;
    }
  if(me.hit[x][y]==true)
    return false;  
  me.hit[x][y]=true;  
  return true;
}

void Game::MyTurn()
{
  //int x=0,y=0;
  bool done=false;
  char change;
  while(!done)
    {
      wclear(stdscr);
      printAll();
      me.ShowShot(me.aimx,me.aimy,him.startx,him.starty);
      move(0,0);
      change=getch();
      mvprintw(0,0," ");
      switch(change)
        {
        case 'w':me.aimy--;
	  if(me.aimy<0)
	    me.aimy=0;
          break;
        case 'a':me.aimx--;
	  if(me.aimx<0)
            me.aimx=0;
          break;
        case 's':me.aimy++;
	  if(me.aimy>9)
            me.aimy=9;
          break;
        case 'd':me.aimx++;
	  if(me.aimx>9)
            me.aimx=9;
          break;
        case ' ':done=true;
          break;
        }
      if(done)
	done=shoot(me.aimx,me.aimy,1);
    }
   him.display();
}
void Game::hisTurn()
{
  int x,y;
  bool done=false;
  do{
  x=rand()%10;
  y=rand()%10;
  if(me.hit[x][y]==false)
    done=true;
  }while(!done);
  me.hit[x][y]=true;
}
void Game::PlaceHim(int size)
{
  int x,y,d;
  bool done=false;
  do{
    x=rand()%10;
    y=rand()%10;
    d=rand()%4;
    int i=0;
    do{
      i++;
      d=(d+1)%4;
      done=him.placeShip(size,d,0,x,y);
    }while(!done&&i<=4);
    if(done)
      return;
  }while(1);
}

bool Game::fullTurn()
{
  MyTurn();
  him.TakeTurn(me.ship,me.hit);
  int x=0,y=0;
  bool Iwin=false,Hewin=false;
  while(y<10&&(!Iwin||!Hewin))
    {
      x=0;
      while(x<10&&(!Iwin||!Hewin))
	{
	  if(him.ship[x][y]==true&&him.hit[x][y]==false)
            Hewin=true;
	  if(me.ship[x][y]==true&&me.hit[x][y]==false)
	    Iwin=true;
	  x++;
	}
      y++;
    }
  if(Iwin&&Hewin)
    return false;
  victory=Iwin;
  defeat=Hewin;
  return true;
}

void Game::printAll()
{
  wclear(stdscr);
  me.display();
  him.display();
  move(row/2,0);//to print the line in the middle
  for(int i=0;i<col;i++)
    printw("=");
  refresh();  
}

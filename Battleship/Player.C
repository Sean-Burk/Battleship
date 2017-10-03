#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "Player.h"
Player::Player()
{
  //  startx=x;
  //  starty=y;
  person=false;
  for(int x=0; x<D;x++)
    for(int y=0;y<D;y++)
      {
	ship[x][y]=0;
	hit[x][y]=0;
      }
}

Player::~Player()
{

}

void Player::display()
{
  int row, col;
  move(starty,startx);
  for(int y=0;y<D;y++)
    {
      for(int x=0;x<D;x++)
        {
          if(hit[x][y]==1&&ship[x][y]==1)
            printw("X ");
          else if(hit[x][y]==1)
            printw("O ");
          else if(ship[x][y]==1&&person)
            printw("# ");
	  else if(ship[x][y]==1)
	    printw("~ ");
          else
            printw("~ ");
        }
      getyx(stdscr,row,col);
      move(row+1,(col-20));
    }
}

bool Player::placeShip(int size,int direction, bool who, int shipx, int shipy)
{
  int row,col;
  getyx(stdscr,row,col);
  int ix,iy;
  int x,y;
  switch(direction)
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
  x=shipx;
  y=shipy;
  for(int i=0;i<size;i++)
    {
      if(x>9||x<0||y>9||y<0)
	return false;
      if(ship[x][y])
	return false;
      x=x+ix;
      y=y+iy;
    }
  for(int i=0;i<size;i++)
    {
      ship[shipx][shipy]=1;
      shipx=shipx+ix;
      shipy=shipy+iy;
    }
  return true;
}



#include <iostream>
#include <ncurses.h>
#include "Person.h"

void Person::PlaceShip(int size)
{
  int row,col;
  getmaxyx(stdscr,row,col);
  move(row/2,(col-61)/2);
  printw("Choose a location and direction for a ship of size %d: ",size);

  int x=0,y=0,d=1;
  bool done=0;
  char change;
  while(!done)
    {
      wclear(stdscr);
      mvprintw(0,0,"Choose a location and direction for a ship of size %d: ",size);
      display();
      ShowShip(x,y,d,size);
      move(0,0);
      change=getch();
      mvprintw(0,0," ");
      switch(change)
	{
	case 'w':y--;
	  if(y<0)
	    y=0;
	  break;
	case 'a':x--;
          if(x<0)
            x=0;
	  break;
	case 's':y++;
          if(y>9)
            y=9;
	  break;
	case 'd':x++;
          if(x>9)
            x=9;
	  break;
	case 'q':d--;if(d==-1)d=3;
	  break;
	case 'e':d++;if(d==4)d=0;
	  break;
	case ' ':done=true;
	  break; 
	default:
	  break;
	}
      if(done)
	done=placeShip(size,d,1,x,y);
    }
  return;
}

void Person::PlaceAll()
{
  int row,col;
  display();
  PlaceShip(5);
  display();
  PlaceShip(4);
  display();
  PlaceShip(3);
  display();
  PlaceShip(3);
  display();
  PlaceShip(2);
  display();
  getch();
}

void Person::ShowShip(int x,int y,int d,int s)
{
  int ix,iy;
  x=startx+x*2;
  y=starty+y;
  //  move(y,x);
  // printw("#");
  switch(d)
    {
    case 0:ix=0; iy=-1;
      break;
    case 1:ix=2; iy=0;
      break;
    case 2:ix=0; iy=1;
      break;
    case 3:ix=-2; iy=0;
      break;
    }
  for(int i=0;i<s;i++)
    {
      mvprintw(y,x,"#");
      x=x+ix;
      y=y+iy;
    }
  refresh();
}

void Person::ShowShot(int x,int y,int xi,int yi)
{

  x=xi+x*2;
  y=yi+y;
  mvprintw(y,x,"*");
  refresh();
}

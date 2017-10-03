#include <iostream>
#include<cstdlib>
#include <ncurses.h>
#include "Player.h"
#include "Person.h"
#include "Game.h"
using namespace std;


int main()
{
  srand(time(0));
  //grid him,me;
  int row, col;
  bool win=false,lose=false,end=false;
  char command;
  initscr();
  getmaxyx(stdscr,row,col);/* get the number of rows and columns */
  /* to count rows
  for(int i=0;i<row;i++)
    {
      move(i,0);
      printw("%d",i);
    }
  */
  Game play;
  play.me.PlaceAll();
  wclear(stdscr);
  play.printAll();
  while(!end)
    {
      end=play.fullTurn();
      play.printAll();      
    }
  if(play.victory)
    mvprintw(row/2,(col-19)/2,"Victory at last!!!!");
  if(play.defeat)
    mvprintw(0,0,"You lose...");
  refresh();
  getch();

  endwin();
  return 0;
}

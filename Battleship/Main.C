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
  bool win=false,lose=false;
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
  move(row/2,(col-42)/2);
  printw("Type a command(L for a list of commands): ");
  refresh();
  command=getch();
  move(row/2,0);//to print the line in the middle
  for(int i=0;i<col;i++)
    printw("=");

  while(command!='d')
    {
      switch(command)
        {
        case 'm'://wclear(stdscr);
	  move(row/2,0);
	  for(int i=0;i<col;i++)
	    printw("=");
	  play.me.display();
	  move((row/2),(col-16)/2);
	  refresh();
	  getch();
          break;
	case 'h'://wclear(stdscr);
	  move(row/2,0);
	  for(int i=0;i<col;i++)
	    printw("=");
          play.him.display();
	  move((row/2),(col-16)/2);
	  refresh();
	  getch();
	  break;
	case 'n':wclear(stdscr);
	  mvprintw((row/2),(col-13)/2,"Game not Done");
	  refresh();
	  break;
        case 'l':wclear(stdscr);
	  move((row/2),(col-48)/2);
	  printw("dispMe=M, dispHim=H, newGame=N, playGame=P, done=D, placeShip=s");
	  refresh();
          break;
	case 's':wclear(stdscr);
	  play.me.PlaceAll();
	  refresh();
	  wclear(stdscr);
	  break;
	case 't':
	  play.MyTurn();
	  break;
	  //case 'P': newGame(him, me);
          //do{
	  // win=myTurn(him, me);
          //  if(win)
          //    ;
          //  else
          //    {
          //      lose=hisTurn(him,me);
          //    }
	  // }while(!win&&!lose);
	  // if(win)
          //  cout<<"Congromulations you win!!\n";
          //else
	  // cout<<"The computer wins...";
	  // break;
        case 'd':return 0;
	}
      move((row/2),(col-16)/2);
      printw("Type a command: ");
      refresh();
      command=getch();
      mvprintw((row/2),(col-16)/2,"==================");
    }
  
  //getch();
  endwin();
  return 0;
}

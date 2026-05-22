#include <ncurses.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

static void finish(int sig);

int main()
{
  char mesg[] = "Press any key to start to Start";
  char str[80];
  int row,col;
  int it = 0;
  char ctl;

  initscr();
  getmaxyx(stdscr, row, col);
  mvprintw(row/2,(col-strlen(mesg))/2,"%s", mesg);
  refresh();
  getch();
  
  for (;;)
  {
    ctl = getch();
    if(ctl == 'q')
    {
      finish(0);
      break;
    }
    if(ctl == ' ')
    {
      // jump
      refresh();
      printw("indexing");
    }
    it+=1;
  }

  return 0;
}

static void finish(int sig)
{
  endwin();
  exit(0);
}

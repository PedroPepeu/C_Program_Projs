#include <ncurses.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>

int *ctl;
int *it = 0;
int *it_ch = 0;
int *loss = 0;
static void finish(int sig);
void* char_func(void* arg);

int main()
{
  char mesg[] = "Press any key to start to Start";
  char str[80];
  int row,col;
  char ctl;

  initscr();
  getmaxyx(stdscr, row, col);
  mvprintw(row/2,(col-strlen(mesg))/2,"%s", mesg);
  refresh();
  getch();

  pthread_t thread_char;

  pthread_create(&thread_char, NULL, char_func, NULL);

  for (;;)
  {
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
}

void* char_func(void* arg)
{
  ctl = getch();
  return NULL;
}

static void finish(int sig)
{
  pthread_join(thread_char, NULL);
  endwin();
  exit(0);
}

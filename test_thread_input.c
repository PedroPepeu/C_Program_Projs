#include <pthread.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int UP = 1;
const int DOWN = 2;

int cmm;

void* func(void* arg);

int main()
{
  initscr();
  refresh();

  pthread_t thread1;

  pthread_create(&thread1, NULL, func, NULL);

  for (;;)
  {
    char ch = getch();
    if (cmm == UP) printw("UP");
    else if (cmm == DOWN) printw("DOWN");
    if (ch == 'q') break;
  }

  pthread_cancel(thread1);
  pthread_join(thread1, NULL);
  endwin();
  return 0;
}

void* func(void* arg)
{
  while(1)
  {
    refresh();
    char inp = getch();
    if (inp == ' ') cmm = UP;
    else cmm = DOWN;
    sleep(1);
  }
  return NULL;
}

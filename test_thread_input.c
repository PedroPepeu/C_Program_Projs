#include <pthread.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    if (ch == KEY_ENTER)
    {
      refresh();
      printw("\n");
    }
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
    printw("running");
    sleep(1);
  }
  return NULL;
}

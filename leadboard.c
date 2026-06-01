#include <ncurses.h>
#include "leadboard.h"

void run_leadboard()
{
  clear();

  refresh();

  getch();

  clear();
  refresh();
}

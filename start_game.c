#include <ncurses.h>
#include "start_game.h"

void run_game()
{
  clear();

  refresh();

  getch();

  clear();
  refresh();
}

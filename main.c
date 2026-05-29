#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>
#include "menu_ui.h"
#include "start_game.h"

int main()
{
  int menu_idx;

  init_ui();

  while(1)
  {
    menu_idx = run_menu();

    if (menu_idx == -1 || menu_idx == 4)
    {
      break;
    }

    switch (menu_idx)
    {
      case 0:
        run_game();
        break;
    }

    if (menu_idx != -1)
    {
      printf("Sucess! You choose index: %d\n", menu_idx);
    }
    else
    {
      printf("You canceled with F1\n");
    }
  }

  close_ui();

  printf("Program finished with success");

  return 0;
}

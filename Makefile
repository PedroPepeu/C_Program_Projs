all:
	gcc main.c menu_ui.c start_game.c -o main -lmenu -lncurses

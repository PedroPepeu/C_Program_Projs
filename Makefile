SRCS = main.c \
			 menu_ui.c \
			 start_game.c \
			 leadboard.c \
			 options.c \
			 sup_dev.c

OUTPUT = main
TEST_OUTPUT = test_app

all: $(OUTPUT)

$(OUTPUT): $(SRCS)
	gcc $(SRCS) -o $(OUTPUT) -lmenu -lncurses

test: $(SRCS)
	gcc $(SRCS) -o $(TEST_OUTPUT) -lmenu -lncurses

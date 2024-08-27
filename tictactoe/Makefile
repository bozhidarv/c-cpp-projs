CC = clang++
DEVFLAGS = --debug
FILES = main.cpp Game.cpp
CR_OUT_DIR = mkdir -p out

compile:
	$(CR_OUT_DIR) && $(CC) $(FILES) -o ./out/tictactoe

compile-dev:
	$(CR_OUT_DIR) && $(CC) $(FILES) $(DEVFLAGS) -o ./out/tictactoe

run:
	./out/tictactoe

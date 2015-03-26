all:
	gcc -Wall -ansi -pedantic src/main.c src/commands.c src/drawing.c src/io.c -Iinclude -o bin/runMe -lncurses
run:
	./bin/runMe

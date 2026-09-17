CC = gcc
SRC = main.c
OUT = main
FLAGS = -Wall -Werror

all: main
main:
	$(CC) $(FLAGS) $(SRC) -o $(OUT)

.PHONY: clean
clean:
	rm $(OUT)
CC = gcc
CFLAGS = -g -Wall

all: main

main: main.c readFile_randWord.c functions.c
    $(CC) $(CFLAGS) main.c readFile_randWord.c functions.c -o main -lm

clean:
    rm -f main

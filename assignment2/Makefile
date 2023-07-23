CC = gcc
CFLAGS = -g -Wall -Wextra
EXECUTABLE = main
CFILES = main.c readFile_randWord.c functions.c

all: $(EXECUTABLE)

$(EXECUTABLE): $(CFILES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(CFILES)

clean:
	rm -f $(EXECUTABLE)
CC = gcc
CFLAGS = -g -Wall -Wextra
EXECUTABLE = main
CFILES = main.c readFile_randWord.c functions.c
HEADERS = constants.h functions.h readFile_randWord.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(CFILES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(CFILES)

clean:
	rm -f $(EXECUTABLE)
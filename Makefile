# compiler
CC = gcc

# compiler flags
CCFLAGS = -Wall

# files to be included
FILES = src/main.c src/terminal.c src/stack.c

all:
	${CC} ${CCFLAGS} ${FILES} -o textEditor

clean:
	rm -rf textEditor


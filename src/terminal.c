/**
 * @file    terminal.c
 * @author  Hamza Siddiqui & Mustafa Siddiqui
 * @brief   Definitions for functions defined in terminal.h
 * @date    2022-02-02
 */

#include <stdio.h>          // perror()
#include <stdlib.h>         // exit()
#include <unistd.h>         // STDIN_FILENO
#include <termios.h>        // tcsetattr(), tcgetattr()
//-//
#include "../inc/terminal.h"

// termios struct to store original terminal settings
struct termios orig_termios;

// print error message & exit program
void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

// disable raw mode for terminal on exit
void disableRawMode(void) {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) {
        die("tcsetattr");
    }
}

// raw mode for terminal
void enableRawMode(void) {
    // storing original terminal attributes
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
        die("tcsetattr");
    }

    // disabling raw mode on program exit
    atexit(disableRawMode);

    // raw struct to store new terminal settings (turning off previous terminal's flags)
    struct termios raw = orig_termios;

    // input flags: fixing ctrl+m, disabling other control inputs
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

    // output flags: turning off all output processing features ("\n" to "\r\n")
    raw.c_oflag &= ~(OPOST);

    // control flags: turning off miscellaneous flags
    raw.c_cflag |= (CS8);

    // local flags: disabling echo feature, canonical mode, control inputs
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    // passing modifed struct to tcsetattr() to set new terminal attributes
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        die("tcsetattr");
    }
}
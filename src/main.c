/** @file   main.c
 *  @brief  Main driver code for text-editor.
 *  @author Mustafa Siddiqui & Hamza Siddiqui
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>   // iscntrl()

struct termios orig_termios;

/**
 * @brief 
 * 
 * @param s 
 */
void die(const char *s);

/**
 * @brief 
 * 
 */
void disableRawMode(void);

/**
 * @brief 
 * 
 */
void enableRawMode(void);

int main() {
   enableRawMode();

   while (1) {
      char c = '\0';
      read(STDIN_FILENO, &c, 1);
      if (iscntrl(c)) {
         printf("%d\r\n", c);
      }
      else {
         printf("%d ('%c')\r\n", c, c);
      }
      if (c == 'q') break;
   }
   
   return 0;
}

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
   if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
      die("tcsetattr");
   }
   atexit(disableRawMode);

   struct termios raw = orig_termios;
   raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
   raw.c_oflag &= ~(OPOST);
   raw.c_cflag |= (CS8);
   raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

   if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
      die("tcsetattr");
   }
}

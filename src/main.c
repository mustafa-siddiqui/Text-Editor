/** @file   main.c
 *  @brief  Main driver code for text-editor.
 *  @author Mustafa Siddiqui & Hamza Siddiqui
 */

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

struct termios orig_termios;

//print error message
//exit program
void die(const char *s) {
   perror(s);
   exit(1);
}

//disable raw mode for terminal
//on exit
void disableRawMode () {
   if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) {
      die("tcsetattr");
   }
   
}

//raw mode for terminal
void enableRawMode () {
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


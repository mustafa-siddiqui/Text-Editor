/** @file   main.c
 *  @brief  Main driver code for text-editor.
 *  @author Mustafa Siddiqui & Hamza Siddiqui
 */

#include <stdio.h>
#include <unistd.h>  // STDIN_FILENO
#include <ctype.h>   // iscntrl()
#include <errno.h>   //errrno
//-//
#include "../inc/terminal.h"

/* macro to mirror ctrl key functionality
bitwise-ANDs 'key' character with 00011111
to map character to bytes 1-26*/
#define CTRL_KEY(key) ((key) & 0x1f)

int main() {
   enableRawMode();

   while (1) {
      char c = '\0';
      if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die ("read");

      // check if character is a control key
      if (iscntrl(c)) {
         printf("%d\r\n", c);
      }
      else {
         printf("%c\r\n", c);
      }
      if (c == CTRL_KEY('c')) break;
   }
   
   return 0;
}
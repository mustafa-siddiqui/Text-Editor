/** @file   main.c
 *  @brief  Main driver code for text-editor.
 *  @author Mustafa Siddiqui & Hamza Siddiqui
 */

#include <stdio.h>
#include <unistd.h>  // STDIN_FILENO
#include <ctype.h>   // iscntrl()
//-//
#include "../inc/terminal.h"

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

      // exit if input = 'q'
      if (c == 'q')
         break;
   }
   
   return 0;
}
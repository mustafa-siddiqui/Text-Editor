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

      // check if character is a control key
      if (iscntrl(c)) {
         // detect ctrl + c
         if (c == 3)
            break;
         printf("%d\r\n", c);
      }
      else {
         printf("%c\r\n", c);
      }
   }
   
   return 0;
}
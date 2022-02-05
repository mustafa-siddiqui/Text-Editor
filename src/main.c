/** @file   main.c
 *  @brief  Main driver code for text-editor.
 *  @author Mustafa Siddiqui & Hamza Siddiqui
 *  @date   2022-02-05
 */

#include <stdio.h>
#include <stdlib.h>  // malloc()
#include <unistd.h>  // STDIN_FILENO
#include <ctype.h>   // iscntrl()
#include <errno.h>   // errno
//-//
#include "../inc/terminal.h"
#include "../inc/stack.h"

// macro to detect ctrl key + another key (alphabet) press
// bitwise-ANDs 'key' character with 00011111
// to map character to bytes 1-26
#define CTRL_KEY(key) ((key) & 0x1f)

int main() {
   enableRawMode();

   // initialize stack
   Node* top = (Node*) malloc(sizeof(Node));
   top = NULL;

   while (1) {
      char c = '\0';
      if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
         die("read");

      // check if character is a control key
      if (iscntrl(c)) {
         //printf("%d\r\n", c);

         // delete character if backspace key (delete key on mac) is pressed
         if (c == 0x7f) {
            // continue on to next key press if stack empty
            if (top == NULL) {
               continue;
            }

            // else delete letter from stack
            top = pop(top);
            disableRawMode();
            printStack(top);
            enableRawMode();
         }
      }
      else {
         // add letters onto stack & print
         top = push(top, c);
         disableRawMode();
         printStack(top);
         enableRawMode();
      }

      if (c == CTRL_KEY('c'))
         break;
   }
   
   disableRawMode();
   freeStack(top);

   return 0;
}
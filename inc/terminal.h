/**
 * @file    terminal.h
 * @author  Hamza Siddiqui
 * @brief   Function declarations relating to terminal I/O.
 * @date    2022-02-02
 */

/**
 * @brief   Print error message and exit program.
 * @param   s: Error message to display
 * @return  NULL
 */
void die(const char *s);

/**
 * @brief   Disable raw mode upon program exit.
 * @param   NULL
 * @return  NULL
 */
void disableRawMode(void);

/**
 * @brief   Enable raw mode for terminal - makes it possible
            to take input as keys are pressed (no need for new 
            line character).
 * @param   NULL
 * @return  NULL
 */
void enableRawMode(void);

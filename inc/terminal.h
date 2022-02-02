#pragma once

/**
 * @brief prints error message and exits program
 * 
 * @param s 
 */
void die(const char *s);

/**
 * @brief disables raw mode on program exit
 * 
 */
void disableRawMode(void);

/**
 * @brief enables raw mode for terminal
 * 
 */
void enableRawMode(void);
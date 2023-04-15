#ifndef _TEST_TERMINAL_COLOUR_HPP_
#define _TEST_TERMINAL_COLOUR_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "identifier.h"

// Represents a position on the terminal screen
// Members
// <uint> x - x coordinate
// <uint> y - y coordinate
typedef struct tlPosition
{
  unsigned int x;
  unsigned int y;
} tlPosition;

// Represents a rectangle on the terminal screen
// Members
// tlPosition least - the position of the least x and least y coordinates
// tlPosition most  - the position of the greatest x and greatest y coordinates + 1 (off screen)
typedef struct tlRect
{
  tlPosition least;
  tlPosition most;
} tlRect;

/*
Get and Set the cursor position of a specific terminal window
*/
void tlGetCursorPosition(tlTerminalWindow*, tlPosition*);
void tlSetCursorPosition(tlTerminalWindow*, tlPosition*);

/*
Get and Set the screen dimensions
*/
void tlGetScreenSize(tlTerminalWindow*, tlRect*);
void tlSetScreenSize(tlTerminalWindow*, tlRect*);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifndef _TEST_TERMINAL_COLOUR_HPP_
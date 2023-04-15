#ifndef _TEST_TERMINAL_IDENTIFIER_HPP_
#define _TEST_TERMINAL_IDENTIFIER_HPP_

#ifdef __cplusplus
extern "C" {
#endif

/*
Represents a terminal window.
Intended to only be accessed and modified via library functions.
Do not access members directly.
Implementation defined.
*/
typedef struct tlTerminalWindow tlTerminalWindow;

// Returns a handle to the main terminal window
tlTerminalWindow* tlGetCurrentTerminal();

// Frees the memory assigned to the terminal window structure
void tlFreeTerminal(tlTerminalWindow*);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifndef _TEST_TERMINAL_IDENTIFIER_HPP_
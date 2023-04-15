#ifndef _TEST_TERMINAL_IO_HPP_
#define _TEST_TERMINAL_IO_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "identifier.h"

// Read and write text to and from the associated terminal
void tlWrite(tlTerminalWindow*, char const*, size_t);
size_t tlRead(tlTerminalWindow*, char*, size_t);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifndef _TEST_TERMINAL_IO_HPP_
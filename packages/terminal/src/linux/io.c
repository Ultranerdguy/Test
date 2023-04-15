#include "terminal/io.h"
#include "identifier_impl.h"

void tlWrite(tlTerminalWindow* pWindow, char const* pMessage, size_t len)
{
  write(pWindow->m_fileOut, pMessage, len);
}

size_t tlRead(tlTerminalWindow* pWindow, char* pMessage, size_t maxLen)
{
  return read(pWindow->m_fileIn, pMessage, maxLen);
}
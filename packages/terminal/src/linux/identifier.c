#include "identifier_impl.h"
#include <unistd.h>

tlTerminalWindow* tlGetCurrentTerminal()
  tlTerminalWindow* pRet = (tlTerminalWindow*)malloc(sizeof(tlTerminalWindow));
  pRet->m_fileOut = STDOUT_FILENO;
  pRet->m_fileIn = STDIN_FILENO;
  return pRet;
}

void tlFreeTerminal(tlTerminalWindow* pTerminal)
{
  free(pTerminal);
}

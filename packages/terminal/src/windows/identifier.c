#include "identifier_impl.h"

tlTerminalWindow* tlGetCurrentTerminal()
{
  tlTerminalWindow* pRet = malloc(sizeof(*pRet));
  pRet->m_fileOut = GetStdHandle(STD_OUTPUT_HANDLE);
  pRet->m_fileIn = GetStdHandle(STD_INPUT_HANDLE);
  // Use virtual terminal for inputs. This allows for a lot of reuse between linux and windows
  SetConsoleMode(pRet->m_fileOut, ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  return pRet;
}

void tlFreeTerminal(tlTerminalWindow* pTerminal)
{
  free(pTerminal);
}

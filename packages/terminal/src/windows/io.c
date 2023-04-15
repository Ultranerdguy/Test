#include "terminal/io.h"
#include "identifier_impl.h"
#include <Windows.h>
#pragma comment(lib, "user32.lib")

void tlWrite(tlTerminalWindow* pWindow, char const* pMessage, size_t len)
{
  WriteFile(pWindow->m_fileOut, pMessage, (DWORD)len, NULL, NULL);
}

size_t tlRead(tlTerminalWindow* pWindow, char* pMessage, size_t maxLen)
{
  DWORD written = (DWORD)0;
  ReadFile(pWindow->m_fileIn, pMessage, (DWORD)maxLen, &written, NULL);
  return written;
}
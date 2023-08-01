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
  return (size_t)written;
}

void tlClear(tlTerminalWindow* pWindow)
{
  COORD tl = {0,0};
  CONSOLE_SCREEN_BUFFER_INFO s;  
  GetConsoleScreenBufferInfo(pWindow->m_fileOut, &s);
  DWORD written, cells = s.dwSize.X * s.dwSize.Y;
  FillConsoleOutputCharacter(pWindow->m_fileOut, ' ', cells, tl, &written);
  FillConsoleOutputAttribute(pWindow->m_fileOut, s.wAttributes, cells, tl, &written);
  SetConsoleCursorPosition(pWindow->m_fileOut, tl);
}
#include "terminal/screen.h"
#include "identifier_impl.h"
#include <Windows.h>

void tlGetCursorPosition(tlTerminalWindow* pWindow, tlPosition* pPosition)
{
  if (!pWindow || !pPosition) return;
  CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(pWindow->m_fileOut, &info);
  pPosition->x = info.dwCursorPosition.X;
  pPosition->y = info.dwCursorPosition.Y;
}

void tlSetCursorPosition(tlTerminalWindow* pWindow, tlPosition* pPosition)
{
  COORD pos;
  pos.X = pPosition->x;
  pos.Y = pPosition->y;
  SetConsoleCursorPosition(pWindow->m_fileOut, pos);
}

void tlGetScreenSize(tlTerminalWindow* pWindow, tlRect* pRect)
{
  if (!pWindow || !pRect) return;
  CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(pWindow->m_fileOut, &info);
  pRect->least.x = 0;
  pRect->least.y = 0;
  pRect->most.x = info.dwSize.X;
  pRect->most.y = info.dwSize.Y;
}

void tlSetScreenSize(tlTerminalWindow* pWindow, tlRect* pRect)
{
  COORD size;
  size.X = pRect->most.x - pRect->least.x;
  size.Y = pRect->most.y - pRect->least.y;
  SetConsoleScreenBufferSize(pWindow->m_fileOut, size);
}
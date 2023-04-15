#include "terminal/screen.h"
#include "identifier_impl.h"
#include "sys/ioctl.h"

void tlGetCursorPosition(tlTerminalWindow* pWindow, tlPosition* pPosition)
{
}

void tlSetCursorPosition(tlTerminalWindow* pWindow, tlPosition* pPosition)
{
}

void tlGetScreenSize(tlTerminalWindow* pWindow, tlRect* pRect)
{
  struct winsize size;
  ioctl(pWindow->m_fileOut, TIOCGWINSZ, &size);
  pRect->least.x = 0;
  pRect->least.y = 0;
  pRect->most.x = size.ws_col;
  pRext->most.y = size.ws_row;
}

void tlSetScreenSize(tlTerminalWindow* pWindow, tlRect* pRect)
{
  struct winsize size;
  size.ws_col = pRect->most.x - pRect->least.x;
  size.ws_row = pRect->most.y - pRect->least.y;
  ioctl(pWindow->m_fileOut, TIOCSWINSZ, &size);
}
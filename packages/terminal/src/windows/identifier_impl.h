#include "terminal/identifier.h"
#include <Windows.h>
#pragma comment(lib, "user32.lib")

struct tlTerminalWindow
{
  HANDLE m_fileOut;
  HANDLE m_fileIn;
};
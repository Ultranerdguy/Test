#include "Commands/Clear.hpp"
#include "terminal/io.h"

void ClearCommand::execute(std::string const& name, std::string const& args)
{
  tlTerminalWindow* pWindow = tlGetCurrentTerminal();
  tlClear(pWindow);
  tlFreeTerminal(pWindow);
}
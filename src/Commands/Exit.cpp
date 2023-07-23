#include "Commands/Exit.hpp"
#include "app.hpp"

void ExitCommand::init(Process& proc)
{
  pParentApp = &proc.parentApp;
}

void ExitCommand::execute(std::string const& command, std::string const& args)
{
  if (pParentApp) pParentApp->SetRunning(false);
}

void ExitCommand::cleanup()
{
  pParentApp = nullptr;
}
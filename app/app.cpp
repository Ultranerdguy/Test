#include "app.hpp"
#include <system_error>
#include "util/debug.hpp"

App::App()
{
 ProcLog("Initialised");
}

App::~App()
{

}

int App::Run() noexcept
{
  try
  {
    MainLoop();
  }
  catch (std::system_error const& e)
  {
    ProcLog(e.code().value(), "- \"", e.code().message(), "\" -", e.what());
    return e.code().value();
  }
  catch(std::exception const& e)
  {
    ProcLog(e.what());
    return errno;
  }
  catch (...)
  {
    DebugLog("Unknown exception caught");
    DebugLog("Error code:", std::make_error_condition((std::errc)errno).message());
    return errno;
  }
  return 0;
}

void App::MainLoop()
{
  while (m_running)
  {
    LoopStep();
  }
}

void App::LoopStep()
{
  m_running = false;
}
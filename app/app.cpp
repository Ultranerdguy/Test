#include "app.hpp"
#include "util/debug.hpp"

App::App()
{

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
  catch(const std::exception& e)
  {
    Log(e.what());
    return 1;
  }
  catch (...)
  {
    DebugLog("Unknown exception caught");
    return -1;
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
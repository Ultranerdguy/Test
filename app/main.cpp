#include <iostream>
#include <thread>
#include "util/debug.hpp"

class App
{
public:
  App();
  ~App();
  int Run() noexcept
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
private:
  void MainLoop()
  {
    while (m_running)
    {
      LoopStep();
    }
  }
  void Init();
  void LoopStep();
  std::atomic_bool m_running = true;
};

int main()
{
  App mainGame;
  return mainGame.Run();
}

App::App()
{
  Log("Initialised");
}

App::~App()
{
  Log("Exiting");
}

void App::LoopStep()
{
  Log("Loop");
  m_running = false;
}
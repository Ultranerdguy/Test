#include <iostream>
#include <thread>
#include "util/debug.hpp"

class App
{
public:
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
      
    }
  }

  std::atomic_bool m_running = true;
};

int main()
{
  App mainGame;
  return mainGame.Run();
}
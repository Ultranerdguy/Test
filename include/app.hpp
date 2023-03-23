#ifndef _TEST_APP_HPP_
#define _TEST_APP_HPP_

#include <atomic>

class App
{
public:
  App();
  ~App();
  int Run() noexcept;
  template <typename ...Ts>
  inline void ProcLog(Ts... args) const noexcept
  {
    Log("[App]", args...);
  }
private:
  void MainLoop();
  void LoopStep();
  std::atomic_bool m_running = true;
};

#endif // #ifndef _TEST_APP_HPP_
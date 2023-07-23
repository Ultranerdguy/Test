#ifndef _TEST_APP_HPP_
#define _TEST_APP_HPP_

#include "util/debug.hpp"
#include <unordered_map>
#include <thread>
#include <memory>
#include "ICommand.hpp"

class App;

struct Process
{
  using id_t = std::uint32_t;
  App& parentApp;
  id_t id;
  bool kill = false;
  std::thread program;
};

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

  void SetRunning(bool doRun = true);
  void RunCommand(std::string const& commandFull);

private:
  void MainLoop();
  void LoopStep();

  void CreateProcess(ICommand* pCommand, std::string const& commandName, std::string const& args);
  bool running = true;

  std::vector<std::unique_ptr<Process>> processes;
  Process::id_t processCount = 0;

  std::unordered_map<std::string, ICommand*> commandMap;
  std::vector<std::unique_ptr<ICommand>> commands;
};

#endif // #ifndef _TEST_APP_HPP_
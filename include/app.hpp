#ifndef _TEST_APP_HPP_
#define _TEST_APP_HPP_

#include "util/debug.hpp"
#include <unordered_map>
#include <thread>
#include <memory>
#include "CommandManager.hpp"

class App;

struct Process
{
  using id_t = std::uint32_t;
  App& parentApp;
  ICommand::ptr_t pCommand = nullptr;
  id_t id;
  bool kill = false;
  std::thread program;
};

class App
{
public:
  App();
  ~App();
  void RegisterCommand(std::string const& name, ICommandCreator const& command);

  template <typename ...Ts>
  static inline void ProcLog(Ts... args) noexcept
  {
    Log("[App]", args...);
  }

  int Run() noexcept;
  void SetRunning(bool doRun = true);
  void RunCommand(std::string const& commandFull);
  CommandManager& GetCommandManager();

private:
  void MainLoop();
  void LoopStep();

  void CreateProcess(ICommand::ptr_t pCommand, std::string const& commandName, std::string const& args);
  bool running = true;

  std::vector<std::unique_ptr<Process>> processes;
  Process::id_t processCount = 0;
  CommandManager commands;
};

#endif // #ifndef _TEST_APP_HPP_
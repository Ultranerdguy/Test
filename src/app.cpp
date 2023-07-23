#include "app.hpp"
#include <system_error>
#include <unordered_map>
#include <vector>
#include "util/debug.hpp"

// Commands
#include "Commands/OminousReport.hpp"
#include "Commands/Exit.hpp"

App::App()
{
  ProcLog("Initialising");
  
  commands.resize(2);
  commands[0] = std::unique_ptr<ICommand>(new OminousReport);
  commandMap["report"] = commands[0].get();
  commands[1] = std::unique_ptr<ICommand>(new ExitCommand);
  commandMap["exit"] = commandMap["quit"] = commands[1].get();

  std::cin.exceptions(std::ios_base::failbit);
  ProcLog("Initialised");
}

App::~App()
{
  ProcLog("Destroying");
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
  while (running)
  {
    LoopStep();
  }
  for (auto& proc : processes)
  {
    proc->kill = true;
    proc->program.join();
  }
}

void App::LoopStep()
{
  for (auto itr = processes.begin(); itr != processes.end();)
  {
    if (itr->get()->kill)
    {
      itr->get()->program.join();
      itr = processes.erase(itr);
    }
    else ++itr;
  }
  std::cout.put('>');
  std::string line;
  std::getline(std::cin, line);
  RunCommand(line);
}

void App::RunCommand(std::string const& commandFull)
{
  std::stringstream commandStream(commandFull);
  std::string commandName;
  commandStream >> commandName;
  std::string args(std::istreambuf_iterator<char>(commandStream), {});

  if (commandMap.contains(commandName))
  {
    ICommand& command = *commandMap[commandName];
    CreateProcess(&command, commandName, args);
  }
  else
  {
    std::cerr << "Unregistered command: " << commandName << '\n';
  }
}

void App::CreateProcess(ICommand* pCommand, std::string const& commandName, std::string const& args)
{
  std::unique_ptr<Process> newProcess(new Process{*this});
  newProcess->id = ++processCount;
  newProcess->program = std::thread([=, newProcess = newProcess.get()]()
  {
    pCommand->init(*newProcess);
    pCommand->execute(commandName, args);
    pCommand->cleanup();
  });
  newProcess->program.join();
  // processes.emplace_back(std::move(newProcess));
}

void App::SetRunning(bool doRun)
{
  running = doRun;
}
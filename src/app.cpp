#include "App.hpp"
#include <system_error>
#include <unordered_map>
#include <vector>
#include <exception>
#include "util/debug.hpp"

// Singleton interface methods

App App::app;

int App::Run() noexcept
{
  return app.Run_Internal();
}

void App::RegisterCommand(std::string const& name, ICommandCreator const& command)
{
  app.commands.Register(name, command);
}

CommandManager& App::GetCommandManager()
{
  return app.commands;
}

void App::SetRunning(bool doRun)
{
  app.running = doRun;
}

// Instance methods

App::App()
{
  ProcLog("Initialising");

  std::cin.exceptions(std::ios_base::badbit);

  ProcLog("Initialised");
}

App::~App()
{
  ProcLog("Destroying");
}

int App::Run_Internal() noexcept
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
  if (!std::cin) std::cin.clear();
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

  auto pCommand = app.commands.Get(commandName);

  if (pCommand)
  {
    app.CreateProcess(std::move(pCommand), commandName, args);
  }
  else
  {
    std::cerr << "Unregistered command: " << commandName << '\n';
  }
}

void App::CreateProcess(ICommand::ptr_t pCommand, std::string const& commandName, std::string const& args)
{
  std::unique_ptr<Process> newProcess(new Process{*this});
  newProcess->id = ++processCount;
  newProcess->pCommand = std::move(pCommand);
  std::exception_ptr pException;
  newProcess->program = std::thread([=, newProcess = newProcess.get(), &pException]()
  {
    try
    {
      newProcess->pCommand->init(*newProcess);
      newProcess->pCommand->execute(commandName, args);
      newProcess->pCommand->cleanup();
    }
    catch (...)
    {
      pException = std::current_exception();
    }
  });
  newProcess->program.join();
  if (pException) std::rethrow_exception(pException);
  // processes.emplace_back(std::move(newProcess));
}
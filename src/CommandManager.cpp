#include "CommandManager.hpp"

void CommandManager::Register(std::string const& name, ICommandCreator const& command)
{
  Log("Registered command",name);
  commandMap[name] = command.clone();
}

std::unique_ptr<ICommand> CommandManager::Get(std::string const& name)
{
  auto itr = commandMap.find(name);
  if (itr != commandMap.end()) return itr->second->create();
  return nullptr;
}
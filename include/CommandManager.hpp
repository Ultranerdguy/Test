#ifndef _TEST_COMMAND_MANAGER_HPP_
#define _TEST_COMMAND_MANAGER_HPP_

#include "ICommand.hpp"
#include <memory>
#include <unordered_map>
#include "util/debug.hpp"

class CommandManager
{
public:
  void Register(std::string const& name, ICommandCreator const& command);
  ICommand::ptr_t Get(std::string const& name);

private:
  std::unordered_map<std::string, ICommandCreator::ptr_t> commandMap;
};

#endif // #ifndef _TEST_COMMAND_MANAGER_HPP_
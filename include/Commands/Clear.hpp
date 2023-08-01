#ifndef _TEST_COMMANDS_CLEAR_HPP_
#define _TEST_COMMANDS_CLEAR_HPP_

#include "../ICommand.hpp"

struct ClearCommand : ICommand
{
  virtual void init(Process& proc) override {}
  virtual void execute(std::string const& name, std::string const& args) override;
  virtual void cleanup() override {}
};

#endif // #ifndef _TEST_COMMANDS_CLEAR_HPP_
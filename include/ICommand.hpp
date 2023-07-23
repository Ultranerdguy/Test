#ifndef _TEST_ICOMMAND_HPP_
#define _TEST_ICOMMAND_HPP_

#include <string>

struct Process;

struct ICommand
{
  virtual void init(Process& proc) = 0;
  virtual void execute(std::string const& name, std::string const& args) = 0;
  virtual void cleanup() = 0;
};

#endif // #ifndef _TEST_ICOMMAND_HPP_
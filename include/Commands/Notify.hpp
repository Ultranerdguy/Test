#ifndef _TEST_COMMANDS_NOTIFY_HPP_
#define _TEST_COMMANDS_NOTIFY_HPP_

#include "../ICommand.hpp"

class NotifyCommand : public ICommand
{
public:
  virtual void init(Process& proc) override;
  virtual void execute(std::string const& name, std::string const& args) override;
  virtual void cleanup() override;
};

#endif // #ifndef _TEST_COMMANDS_NOTIFY_HPP_
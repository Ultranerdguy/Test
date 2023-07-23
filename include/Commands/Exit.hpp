#ifndef _TEST_COMMANDS_EXIT_HPP_
#define _TEST_COMMANDS_EXIT_HPP_

#include "../ICommand.hpp"

class App;

class ExitCommand : public ICommand
{
public:
  virtual void init(Process& proc) override;
  virtual void execute(std::string const& name, std::string const& args);
  virtual void cleanup();
private:
  App* pParentApp;
};

#endif // #ifndef _TEST_COMMANDS_EXIT_HPP_
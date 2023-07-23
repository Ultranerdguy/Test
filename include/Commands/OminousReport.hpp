#ifndef _TEST_COMMANDS_OMINOUS_REPORT_HPP_
#define _TEST_COMMANDS_OMINOUS_REPORT_HPP_

#include "../ICommand.hpp"

class OminousReport : public ICommand
{
public:
  virtual void init(Process& proc) override {}; // Nop
  virtual void execute(std::string const& name, std::string const& args) override;
  virtual void cleanup() override {}; // Nop
private:
};

#endif // #ifndef _TEST_COMMANDS_OMINOUS_REPORT_HPP_
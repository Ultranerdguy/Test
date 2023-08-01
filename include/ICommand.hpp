#ifndef _TEST_ICOMMAND_HPP_
#define _TEST_ICOMMAND_HPP_

#include <string>
#include <memory>

struct Process;

struct ICommand
{
  using ptr_t = std::unique_ptr<ICommand>;
  virtual void init(Process& proc) = 0;
  virtual void execute(std::string const& name, std::string const& args) = 0;
  virtual void cleanup() = 0;
};

struct ICommandCreator
{
  using ptr_t = std::unique_ptr<ICommandCreator>;
  virtual ICommand::ptr_t create() = 0;
  virtual ptr_t clone() const = 0;
};

template <typename T>
class BasicCommandCreator : public ICommandCreator
{
public:
  virtual ICommand::ptr_t create() override
  {
    return ICommand::ptr_t(new T{});
  }
  virtual ptr_t clone() const override
  {
    return ptr_t(new BasicCommandCreator(*this));
  }
};

#endif // #ifndef _TEST_ICOMMAND_HPP_
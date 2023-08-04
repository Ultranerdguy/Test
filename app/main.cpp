#include "App.hpp"
#include "Commands/Exit.hpp"
#include "Commands/Report.hpp"
#include "Commands/Clear.hpp"
#include "Commands/Notify.hpp"
#include "BuildInfo.hpp"

struct TestCommand : ICommand
{
  virtual void init(Process& proc) override {}
  virtual void execute(std::string const& name, std::string const& args) override 
  {
  }
  virtual void cleanup() override {}
};

int main()
{
  srand(static_cast<unsigned int>(time(nullptr)));
  std::clog << BUILD::NAME_FULL << '\n';
  std::clog << BUILD::SYSTEM << '\n';
  std::clog << "C   compiler: " << BUILD::C_COMPILER << " - " << BUILD::C_COMPILER_VERSION << '\n';
  std::clog << "C++ compiler: " << BUILD::CXX_COMPILER << " - " << BUILD::CXX_COMPILER_VERSION << '\n';

  App::RegisterCommand("exit", BasicCommandCreator<ExitCommand>{});
  App::RegisterCommand("report", BasicCommandCreator<OminousReportCommand>{});
  App::RegisterCommand("clear", BasicCommandCreator<ClearCommand>{});
  App::RegisterCommand("notify", BasicCommandCreator<NotifyCommand>{});
  App::RegisterCommand("test", BasicCommandCreator<TestCommand>{});
  return App::Run();
}
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

  App app;
  app.RegisterCommand("exit", BasicCommandCreator<ExitCommand>{});
  app.RegisterCommand("report", BasicCommandCreator<OminousReportCommand>{});
  app.RegisterCommand("clear", BasicCommandCreator<ClearCommand>{});
  app.RegisterCommand("notify", BasicCommandCreator<NotifyCommand>{});
  app.RegisterCommand("test", BasicCommandCreator<TestCommand>{});
  return app.Run();
}
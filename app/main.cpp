#include "App.hpp"
#include "Commands/Exit.hpp"
#include "Commands/OminousReport.hpp"
#include "Commands/Clear.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif

struct NotifyData
{
  static NOTIFYICONDATA nID;
  NotifyData()
  {
    nID.cbSize = sizeof(nID);
    nID.uVersion = NOTIFYICON_VERSION_4;
    nID.uFlags = NIF_REALTIME | NIF_TIP;
    nID.dwInfoFlags = NIIF_NONE;
    nID.uTimeout = 5000;
    char const title[] = "Warning";
    char const message[] = "A hostile entity has been detected and is rapidly approaching.";
    char const tip[] = "Notifications tip";
    std::memcpy(nID.szInfoTitle, title, min(sizeof(title), sizeof(nID.szInfoTitle)));
    std::memcpy(nID.szInfo, message, min(sizeof(message), sizeof(nID.szInfo)));
    std::memcpy(nID.szTip, tip, min(sizeof(tip), sizeof(nID.szTip)));
    Shell_NotifyIcon(NIM_ADD, &nID);
  }
  ~NotifyData()
  {
    Shell_NotifyIcon(NIM_DELETE, &nID);
    DestroyWindow(nID.hWnd);
  }
};
NOTIFYICONDATA NotifyData::nID{};

struct TestCommand : ICommand
{
  virtual void init(Process& proc) override {}
  virtual void execute(std::string const& name, std::string const& args) override 
  {
    NotifyData::nID.uFlags |= NIF_INFO;
    if (!args.empty())
    {
      std::memcpy(NotifyData::nID.szInfo, args.c_str(), min(args.size(), sizeof(NotifyData::nID.szInfo)));
    }
    if (!Shell_NotifyIcon(NIM_MODIFY, &NotifyData::nID)) std::cerr << "Failed to notify\n";
  }
  virtual void cleanup() override {}
};

int main()
{
  NotifyData id;
  srand(static_cast<unsigned int>(time(nullptr)));
  App::RegisterCommand("exit", BasicCommandCreator<ExitCommand>{});
  App::RegisterCommand("report", BasicCommandCreator<OminousReportCommand>{});
  App::RegisterCommand("clear", BasicCommandCreator<ClearCommand>{});
  App::RegisterCommand("test", BasicCommandCreator<TestCommand>{});
  return App::Run();
}
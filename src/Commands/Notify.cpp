#include "Commands/Notify.hpp"
#include <stdexcept>

#ifdef _WIN32
#include <Windows.h>

struct NotifyData
{
  static NOTIFYICONDATA nID;
  NotifyData()
  {
    nID.cbSize = sizeof(nID);
    nID.uFlags = NIF_REALTIME | NIF_TIP;
    nID.dwInfoFlags = NIIF_NONE;
    nID.uVersion = NOTIFYICON_VERSION_4;
    char const title[] = "Notice";
    char const message[] = "Sample notification using the win32 api";
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

void NotifyCommand::init(Process& proc) {}
void NotifyCommand::cleanup() {}
void NotifyCommand::execute(std::string const& name, std::string const& args) 
{
  static NotifyData id; // init on first call
  NotifyData::nID.uFlags |= NIF_INFO;
  if (!args.empty())
  {
    std::memcpy(NotifyData::nID.szInfo, args.c_str(), min(args.size(), sizeof(NotifyData::nID.szInfo)));
    if (args.size() < sizeof(NotifyData::nID.szInfo)) NotifyData::nID.szInfo[args.size()] = 0;
  }
  if (!Shell_NotifyIcon(NIM_MODIFY, &NotifyData::nID)) throw std::runtime_error("Failed to notify");
}
#else
void NotifyCommand::init(Process& proc) {}
void NotifyCommand::cleanup() {}
[[noreturn]] void NotifyCommand::execute(std::string const& name, std::string const& args)
{
  throw std::logic_error("Not implemented");
}

#endif // #ifdef _WIN32
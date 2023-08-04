#include "Commands/Report.hpp"
#include "app.hpp"
#include <thread>

namespace Reports
{
  struct Report
  {
    char const* name = nullptr;
    char const* abstract = nullptr;
    char const* threatLevel = nullptr;
    char const* location = nullptr;
    char const* protocol = nullptr;
  };

  Report reports[] = {
    {.name = "Report A"
    ,.abstract = "Sample information on report A"
    ,.threatLevel = "0"
    ,.location = "London, UK"
    ,.protocol = "No action required"
    }
    ,
    {.name = "Report B"
    ,.abstract = "Sample information on report B"
    ,.threatLevel = "5"
    ,.location = "Tokyo, Japan"
    ,.protocol = "Enjoy it while it lasts"
    }
    ,
    {.name = "Report C"
    ,.abstract = "Sample information on report C"
    ,.threatLevel = "10"
    ,.location = "new York, USA"
    ,.protocol = "It's already too late"
    }
    ,
    {.name = ""
    ,.abstract = ""
    ,.threatLevel = ""
    ,.location = ""
    ,.protocol = ""
    }
  };
}

void SlowPrint(char const* p)
{
  if (p)
  {
    while (*p != '\0')
    {
      std::cout.put(*p);
      ++p;
      std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
}

void OminousReportCommand::execute(std::string const& name, std::string const& args)
{
  Reports::Report& rep = Reports::reports[rand()%(sizeof(Reports::reports)/sizeof(Reports::Report))];

  if (rep.name) { SlowPrint("Name: "); SlowPrint(rep.name); std::cout.put('\n'); }
  if (rep.abstract) { SlowPrint("Abstract: "); SlowPrint(rep.abstract); std::cout.put('\n'); }
  if (rep.threatLevel) { SlowPrint("Threat Level: "); SlowPrint(rep.threatLevel); std::cout.put('\n'); }
  if (rep.location) { SlowPrint("Location: "); SlowPrint(rep.location); std::cout.put('\n'); }
  if (rep.protocol) { SlowPrint("Protocol: "); SlowPrint(rep.protocol); std::cout.put('\n'); }
}
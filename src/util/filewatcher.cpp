#include "util/filewatcher.hpp"
#include <thread>
#include <mutex>
#include <set>

namespace util
{
  class watcher_thread
  {
  public:
    watcher_thread()
    {
      m_updateLoop.swap(std::thread([this]
      {
        while (true)
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(500));
          
          std::lock_guard lock(m_watchersMutex);
          for (auto pWatcher : m_watchers)
          {
            if (pWatcher->UpdateRequired())
            {
              pWatcher->Update();
            }
          }
        }
      }));
    }
    void Add(util::file_watcher* pWatcher)
    {
      std::lock_guard lock(m_watchersMutex);
      m_watchers.insert(pWatcher);
    }
    void Remove(util::file_watcher* pWatcher)
    {
      std::lock_guard lock(m_watchersMutex);
      m_watchers.erase(pWatcher);
    }
  private:
    std::thread m_updateLoop;
    std::set<util::file_watcher*> m_watchers;
    std::mutex m_watchersMutex;
  } watcherThread;
}

util::file_watcher::file_watcher()
{
  watcherThread.Add(this);
}
util::file_watcher::~file_watcher()
{
  watcherThread.Remove(this);
}

util::file_watcher::file_watcher(std::filesystem::path path)
  : file_watcher()
{
  Attach(path);
}

void util::file_watcher::Attach(std::filesystem::path path)
{
  m_path = path;
  if (std::filesystem::exists(m_path))
  {
    m_lastWriteTime = std::filesystem::last_write_time(m_path);
  }
}

bool util::file_watcher::UpdateRequired() const
{
  return !m_path.empty() && std::filesystem::exists(m_path) && (m_lastWriteTime != std::filesystem::last_write_time(m_path));
}

void util::file_watcher::Update()
{
  m_lastWriteTime = std::filesystem::last_write_time(m_path);
  if (m_update)
  {
    m_update(m_path);
  }
}

void util::file_watcher::SetUpdate(update_type update)
{
  m_update = update;
}
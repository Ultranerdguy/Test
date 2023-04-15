#ifndef _TEST_UTIL_FILEWATCHER_HPP_
#define _TEST_UTIL_FILEWATCHER_HPP_

#include <filesystem>
#include <functional>

namespace util
{
  class file_watcher
  {
  public:
    using update_type = std::function<void(std::filesystem::path const&)>;

    file_watcher();
    file_watcher(std::filesystem::path path);
    ~file_watcher();

    void Attach(std::filesystem::path path);

    bool UpdateRequired() const;
    void Update();

    void SetUpdate(update_type update);
  private:
    std::filesystem::path m_path;
    std::filesystem::file_time_type m_lastWriteTime;
    update_type m_update;
  };
}

#endif // #ifndef _TEST_UTIL_FILEWATCHER_HPP_
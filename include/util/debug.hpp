#ifndef _TEST_UTIL_DEBUG_LOG_HPP_
#define _TEST_UTIL_DEBUG_LOG_HPP_

#ifndef NDEBUG
#include <sstream>
struct add_space{std::stringstream data;};
template <typename T>
inline add_space& operator<<(add_space& l, T const& r)
{
  l.data << r << ' ';
  return l;
}
template <typename ...Ts>
inline void Log(Ts const&... args)
{
  add_space line;
  (line << ... << args);
  std::clog << line.data.str() << '\n';
}
#define DebugLog(...) \
{\
  Log(__FILE__, " > ", __LINE__, ": ", __VA_ARGS__);\
}

#define DebugThrow(class, message) \
{\
  std::stringstream _debug_throw_stream;\
  _debug_throw_stream << __FILE__ << " > " << __LINE__ << ": " << message << '\n';\
  throw class(_debug_throw_stream.str().c_str());\
}
#else
#define Log(...) ;
#define DebugLog(...) ;
#define DebugThrow(...) ;
#endif // #ifndef NDEBUG

#endif // #ifndef _TEST_UTIL_DEBUG_LOG_HPP_
#ifndef _TEST_UTIL_RAII_HPP_
#define _TEST_UTIL_RAII_HPP_

#include <iostream>

namespace util
{
// RedirectStream
  // Temporarily replaces the buffer of src with the buffer of dst, allowing streams to be redirected
  // Restores the src buffer on destruction
  // Allows redirecting input to input, or output to output, but not mixing
  template <typename CHAR_T>
  class redirect_stream
  {
  public:
    redirect_stream(std::basic_istream<CHAR_T>& src, std::basic_istream<CHAR_T> const& dst)
      : m_src(src)
    {
      Redirect(src, dst);
    }
    redirect_stream(std::basic_ostream<CHAR_T>& src, std::basic_ostream<CHAR_T> const& dst)
      : m_src(src)
    {
      Redirect(src, dst);
    }
    virtual ~redirect_stream()
    {
      Reset();
    }

  private:
    void Redirect(std::basic_ios<CHAR_T>& src, std::basic_ios<CHAR_T> const& dst)
    {
      m_pOldBuf = m_src.rdbuf(dst.rdbuf());
    }
    void Reset()
    {
      m_src.rdbuf(m_pOldBuf);

    }
    std::basic_ios<CHAR_T>& m_src;
    std::basic_streambuf<CHAR_T>* m_pOldBuf = nullptr;
  };

  // RAIICache
  // Resets the tracked variable back to its original state on destruction
  template <typename T>
  class RAIICache
  {
  public:
    RAIICache(T& var)
      : m_var(var)
      , m_oldVal(var)
    {}

    RAIICache(T& var, T newVal)
      : m_var(var)
      , m_oldVal(std::move(var))
    {
      var = newVal;
    }

    ~RAIICache()
    {
      m_var = std::move(m_oldVal);
    }

  private:
    T& m_var;
    T m_oldVal;
  };
}
#endif
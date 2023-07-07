#ifndef _TEST_NETSIM_INTERFACES_HPP_
#define _TEST_NETSIM_INTERFACES_HPP_

#include <cstddef>

struct IGenericIO
{
  virtual std::size_t Read(void* pBuffer, std::size_t maxSize) = 0;
  virtual void Write(void const* pBuffer, std::size_t size) = 0;
};

#endif // #ifndef _TEST_NETSIM_INTERFACES_HPP_
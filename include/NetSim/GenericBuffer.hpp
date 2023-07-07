#ifndef _TEST_NETSIM_GENERICBUFFER_HPP_
#define _TEST_NETSIM_GENERICBUFFER_HPP_

#include <cstddef>
#include <utility>

// As this is a generic byte buffer, use malloc and free to allocate space
class GenericBuffer
{
public:
  GenericBuffer(void const* pBuffer, std::size_t size);
  GenericBuffer(std::size_t size);
  GenericBuffer(GenericBuffer const& cpy);
  GenericBuffer(GenericBuffer&& mv);
  ~GenericBuffer();
  GenericBuffer& operator=(GenericBuffer b);

  void* GetBuffer();
  void const* GetBuffer() const;
  std::size_t GetBufferSize() const;

  void swap(GenericBuffer& b);
private:
  void* m_pBuffer = nullptr;
  std::size_t m_bufferSize = 0;
};

namespace std
{
  template <>
  void swap(GenericBuffer& a, GenericBuffer& b);
}

#endif // #ifndef _TEST_NETSIM_GENERICBUFFER_HPP_
#include "NetSim/GenericBuffer.hpp"

GenericBuffer::GenericBuffer(void const* pBuffer, std::size_t size)
{
  // Use the swap approach for memory safety
  GenericBuffer copy(size);
  std::memcpy(copy.GetBuffer(), pBuffer, size);
  swap(copy);
}
GenericBuffer::GenericBuffer(std::size_t size)
{
  m_pBuffer = malloc(size);
  if (m_pBuffer) m_bufferSize = size;
  else throw std::runtime_error("Malloc failed in GenericBuffer");
}
GenericBuffer::GenericBuffer(GenericBuffer const& cpy)
  : GenericBuffer(cpy.GetBufferSize())
{
  std::memcpy(GetBuffer(), cpy.GetBuffer(), GetBufferSize());
}
GenericBuffer::GenericBuffer(GenericBuffer&& mv)
{
  swap(mv);
}
GenericBuffer::~GenericBuffer()
{
  free(m_pBuffer);
}
// Use value instead of either move or copy. The constructor can figure out which
GenericBuffer& GenericBuffer::operator=(GenericBuffer b)
{
  swap(b);
  return *this;
}

void* GenericBuffer::GetBuffer()
{
  return m_pBuffer; 
}

void const* GenericBuffer::GetBuffer() const 
{
  return m_pBuffer;
}
std::size_t GenericBuffer::GetBufferSize() const
{
  return m_bufferSize;
}

void swap(GenericBuffer& b)
{
  using std::swap;
  swap(m_pBuffer, b.m_pBuffer);
  swap(m_bufferSize, b.m_bufferSize);
}

namespace std
{
  template <>
  void swap(GenericBuffer& a, GenericBuffer& b)
  {
    a.swap(b);
  }
}
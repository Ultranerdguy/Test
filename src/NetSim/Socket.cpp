#include "NetSim/Socket.hpp"
#include <cstring>

Socket::Socket(Socket::SOCK_TYPE type) 
  : m_type(type) 
{}

void Socket::Connect(Socket* pTarget)
{
  // Disconnect the sockets that are currently connected to this and target (if available)
  if (m_pConnected) m_pConnected->m_pConnected = nullptr;
  if (pTarget->m_pConnected) pTarget->m_pConnected->m_pConnected = nullptr;

  // Connect this and target together
  m_pConnected = pTarget;
  pTarget->m_pConnected = this;
}

Socket::SOCK_TYPE Socket::GetProtocol()
{
  return m_type; 
}

// Read pulls from this buffer
std::size_t Socket::Read(void* pBuffer, std::size_t maxSize)
{
  std::size_t copySize = std::min(maxSize, m_buffer.GetBufferSize());
  std::memcpy(pBuffer, m_buffer.GetBuffer(), copySize);
  return copySize;
}

// Write pushes to connected buffer (overwriting existing buffer)
void Socket::Write(void const* pBuffer, std::size_t size)
{
  if (m_pConnected)
  {
    m_pConnected->m_buffer = GenericBuffer(pBuffer, size);
  }
}
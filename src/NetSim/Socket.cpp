#include "NetSim/Socket.hpp"

Socket::Socket(Socket::PROTOCOL proto = Socket::PROTOCOL::RAW) 
  : m_proto(proto) 
{}
void Socket::Connect(Socket* pTarget = nullptr)
{
  // Disconnect the sockets that are currently connected to this and target (if available)
  if (m_pConnected) m_pConnected->m_pConnected = nullptr;
  if (pTarget->m_pConnected) pTarget->m_pConnected->m_pConnected = nullptr;

  // Connect this and target together
  m_pConnected = pTarget;
  pTarget->m_pConnected = this;
}
Socket::PROTOCOL Socket::GetProtocol()
{
  return m_proto; 
}
// Read pulls from this buffer
virtual std::size_t Socket::Read(void* pBuffer, std::size_t maxSize) override
{
  std::size_t copySize = std::min(maxSize, m_buffer.GetBufferSize());
  std::memcpy(pBuffer, m_buffer.GetBuffer(), copySize);
}
// Write pushes to connected buffer (overwriting existing buffer)
virtual void Socket::Write(void const* pBuffer, std::size_t size) override
{
  if (m_pConnected)
  {
    m_pConnected->m_buffer = GenericBuffer(pBuffer, size);
  }
}
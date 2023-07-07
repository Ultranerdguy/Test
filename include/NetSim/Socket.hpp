#ifndef _TEST_NETSIM_SOCKET_HPP_
#define _TEST_NETSIM_SOCKET_HPP_

#include "Interfaces.hpp"
#include "GenericBuffer.hpp"

struct IP
{
  std::uint8_t data[4]{};
};
using PORT = std::uint16_t;

class Socket : public IGenericIO
{
public:
  enum class PROTOCOL {RAW, ETHERNET};
  Socket(PROTOCOL proto = PROTOCOL::RAW);
  void Connect(Socket* pTarget = nullptr);
  PROTOCOL GetProtocol();
  // Read pulls from this buffer
  virtual std::size_t Read(void* pBuffer, std::size_t maxSize) override;
  // Write pushes to connected buffer (overwriting existing buffer)
  virtual void Write(void const* pBuffer, std::size_t size) override;
  
private:
  PROTOCOL m_proto = PROTOCOL::RAW;
  Socket* m_pConnected = nullptr;
  GenericBuffer m_buffer{1<<10};
};

#endif // #ifndef _TEST_NETSIM_SOCKET_HPP_
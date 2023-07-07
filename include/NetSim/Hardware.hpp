#ifndef _TEST_NETSIM_HARDWARE_HPP_
#define _TEST_NETSIM_HARDWARE_HPP_

#include <vector>
#include "Socket.hpp"

class Hardware
{
public:
  void CreateSocket(Socket::PROTOCOL protocol);
  auto& GetSockets();
  auto const& GetSockets() const;
private:
  std::vector<Socket> m_sockets{{Socket::PROTOCOL::ETHERNET}};
};

#endif // #ifndef _TEST_NETSIM_HARDWARE_HPP_
#ifndef _TEST_NETSIM_HARDWARE_HPP_
#define _TEST_NETSIM_HARDWARE_HPP_

#include <vector>
#include "Socket.hpp"

class Hardware
{
public:
  using socket_storage_t = std::vector<Socket>;
  void CreateSocket(Socket::SOCK_TYPE protocol);
  socket_storage_t& GetSockets();
  socket_storage_t const& GetSockets() const;
private:
  socket_storage_t m_sockets{{Socket::SOCK_TYPE::ETHERNET}};
};

#endif // #ifndef _TEST_NETSIM_HARDWARE_HPP_
#include "NetSim/Hardware.hpp"

void Hardware::CreateSocket(Socket::SOCK_TYPE protocol)
{
  m_sockets.emplace_back(protocol);
}

Hardware::socket_storage_t& Hardware::GetSockets() 
{
  return m_sockets;
}

Hardware::socket_storage_t const& Hardware::GetSockets() const
{
  return m_sockets;
}
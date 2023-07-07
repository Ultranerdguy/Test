#include "NetSim/Hardware.hpp"

void Hardware::CreateSocket(Socket::PROTOCOL protocol)
{
  m_sockets.emplace_back(protocol);
}

auto& Hardware::GetSockets() 
{
  return m_sockets;
}

auto const& Hardware::GetSockets() const
{
  return m_sockets;
}
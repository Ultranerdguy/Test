#include "NetSim/OSBase.hpp"

OSBase::OSBase(Hardware& hardware)
{
  auto& sockets  = hardware.GetSockets();
  for (auto& socket : sockets)
  {
    m_protocolSocketMap[socket.GetProtocol()].push_back(&socket);
  }
}
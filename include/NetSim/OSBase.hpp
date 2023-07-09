#ifndef _TEST_NETSIM_OSBASE_HPP_
#define _TEST_NETSIM_OSBASE_HPP_

#include <unordered_map>
#include <vector>
#include "Hardware.hpp"
#include "Socket.hpp"

class OSBase
{
public:
  OSBase(Hardware& hardware);
private:
  std::unordered_map<Socket::SOCK_TYPE, std::vector<Socket*>> m_protocolSocketMap;
};

#endif // #ifndef _TEST_NETSIM_OSBASE_HPP_
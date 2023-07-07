#ifndef _TEST_NETSIM_COMPUTER_HPP_
#define _TEST_NETSIM_COMPUTER_HPP_

#include <memory>
#include "OSBase.hpp"
#include "Hardware.hpp"

class Computer
{
public:
private:
  Hardware board;
  std::unique_ptr<OSBase> os{new OSBase{board}};
};

#endif // #ifndef _TEST_NETSIM_COMPUTER_HPP_
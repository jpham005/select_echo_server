#include "Socket.hpp"

#include <vector>

#include <iostream>
#include <unistd.h>
int main() {

  std::vector<class Socket> vec;

  {
    class Socket server;
    vec.push_back(server);
  }

  vec.begin()->accept();
}

#include "Socket.hpp"

#include <vector>

int main() {

  std::vector<class Socket> vec;

  {
    class Socket server;
    vec.push_back(server);
  }

  std::cout << "accepted " << accept(event.ident, NULL, NULL) << std::endl;
}

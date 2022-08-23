#pragma once

#include "Socket.hpp"

class Server : public Socket {
private:
  Server& operator=(const Server& other);

public:
  Server(const std::string& addr = "0.0.0.0", uint16_t port = 7070, int backlog = 1024);
  Server(const Server& other);
  ~Server();
};

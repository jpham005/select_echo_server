#pragma once

#include "Socket.hpp"

class Client : public Socket {
private:
  Client& operator=(const Client& other);

public:
  explicit Client(int fd);
  Client(const Client& other);
  ~Client();

  void connectClient(int server);
};

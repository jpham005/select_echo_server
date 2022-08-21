#pragma once

#include <string>

#include <arpa/inet.h>

class Socket {
private:
  int _fd;

  Socket& operator=(const Socket& other);

public:
  Socket(const std::string& addr = "0.0.0.0", uint16_t port = 8080, int backlog = 1024);
  Socket(const Socket& other);
  ~Socket();

  void close_server() const throw();

  int getfd() const throw { return _fd; }
};

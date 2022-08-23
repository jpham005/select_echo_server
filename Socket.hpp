#pragma once

#include <string>

#include <arpa/inet.h>

#include <sys/socket.h>
#include <sys/select.h>

#include <iostream>
class Socket {
private:
  Socket& operator=(const Socket& other);

protected:
  int _fd;

public:
  Socket();
  explicit Socket(int fd);
  Socket(const Socket& other);
  ~Socket();

  void closeSocket() const throw();

  int getFd() const throw();
};

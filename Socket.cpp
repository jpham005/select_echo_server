#include "Socket.hpp"

#include <iostream>

#include <unistd.h>

Socket::Socket() : _fd(-1) {}

Socket::Socket(int fd) : _fd(fd) {}

Socket::Socket(const Socket &other) : _fd(other._fd) {}

Socket::~Socket() {}

void Socket::closeSocket() const throw() {
  close(_fd);
  std::cout << "Server closed" << std::endl;
}

int Socket::getFd() const throw() {
  return _fd;
}

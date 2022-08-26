#include "Client.hpp"

#include <iostream>

#include <unistd.h>

Client::Client(int fd) : Socket(fd) {}

Client::Client(const Client &other) : Socket(other._fd) {}

Client::~Client() {}

void Client::connectClient(int server) {
  _fd = accept(server, NULL, NULL);

  if (_fd) {
    throw std::runtime_error("accept error");
  }

  std::cout << "client connected: fd: " << _fd << std::endl;
}

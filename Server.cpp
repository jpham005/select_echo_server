#include "Server.hpp"

#include <iostream>

#include <fcntl.h>
#include <sys/socket.h>
#include <unistd.h>

Server::Server(const std::string& addr, uint16_t port, int backlog) : Socket(socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) {
  if (_fd == -1) {
    perror(NULL);
    throw std::runtime_error("Server: Fail to create Socket");
  }

  int truthy = true;
  if (
    setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &truthy, sizeof(truthy))
    || fcntl(_fd, F_SETFL, O_NONBLOCK)
  ) {
    perror(NULL);
    throw std::runtime_error("Server: Fail to set Socket option");
  }

  struct sockaddr_in addr_info;
  memset(&addr_info, 0, sizeof(addr_info));
  addr_info.sin_addr.s_addr = htonl(inet_addr(addr.c_str()));
  addr_info.sin_family = AF_INET;
  addr_info.sin_port = htons(port);

  if (
    bind(_fd, reinterpret_cast<struct sockaddr*>(&addr_info), sizeof(addr_info))
    || listen(_fd, backlog)
  ) {
    perror(NULL);
    throw std::runtime_error("Server: Fail to start listening");
  }

  std::cout << "Server started listening on " << addr << ":" << port << std::endl;
}

Server::Server(const Server &other) : Socket(other._fd) {}

Server::~Server() {}

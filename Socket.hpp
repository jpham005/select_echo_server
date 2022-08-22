#pragma once

#include <string>

#include <arpa/inet.h>

#include <sys/socket.h>
#include <sys/select.h>

#include <iostream>
class Socket {
private:
  int _fd;

  Socket& operator=(const Socket& other);

public:
  Socket(const std::string& addr = "0.0.0.0", uint16_t port = 8080, int backlog = 1024);
  Socket(const Socket& other);
  ~Socket();

  void accept() {
    fd_set readfds;
    FD_SET(_fd, &readfds);
    select(_fd + 1, &readfds, NULL, NULL, NULL);
    std::cout << ::accept(_fd, NULL, NULL) << std::endl;
    perror(NULL);
  }

  void close_server() const throw();

  int getfd() const throw() { return _fd; }
};

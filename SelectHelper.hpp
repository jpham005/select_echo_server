#pragma once

#include <vector>

#include <sys/select.h>

#include "Client.hpp"
#include "Server.hpp"

class SelectHelper {
private: 
  static fd_set _read_fds;
  static fd_set _write_fds;
  static fd_set _error_fds;
  static std::vector<Client> _clients;
  static std::vector<Server> _servers;
  static int _nfds;

  SelectHelper(const SelectHelper& other);
  SelectHelper& operator=(const SelectHelper& other);

public:
  SelectHelper();
  ~SelectHelper();

  void addReadEvent(int fd);
  void addWriteEvent(int fd);
  void addErrorEvent(int fd);

  void deleteReadfds(int fd);
  void deleteWritefds(int fd);
  void deleteErrorfds(int fd);

  void initServer();

  int inspectFds();
};

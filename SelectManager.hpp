#pragma once

#include <vector>

#include <sys/select.h>

class SelectManager {
public:
  typedef std::vector<fd_set> fd_set_container_type;

private:
  static fd_set_container_type _readfds;
  static fd_set_container_type _writefds;
  static fd_set_container_type _errorfds;
  static struct timeval        _select_timeout;

  SelectManager(const SelectManager& other);
  SelectManager& operator=(const SelectManager& other);

public:
  SelectManager();
  ~SelectManager();
};

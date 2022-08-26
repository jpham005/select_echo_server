#pragma once

#include <vector>

#include "SelectHelper.hpp"
#include "Server.hpp"

class Application {
public:
  typedef std::vector<Server> server_container_type;

private:
  static server_container_type _servers;
  static SelectHelper _select_helper;
  static int _nfds;

  Application(const Application& other);
  Application& operator=(const Application& other);

public:
  Application();
  ~Application();

  // may recv server list from conf
  void initServer();
  void run();
};

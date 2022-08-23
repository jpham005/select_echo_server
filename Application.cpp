#include "Application.hpp"

Application::server_container_type Application::_servers;
Application::fd_set_container_type Application::_readfds;
Application::fd_set_container_type Application::_writefds;
Application::fd_set_container_type Application::_errorfds;
struct timeval Application::_select_timeout = { 0, 0 };

Application::Application() {}

Application::~Application() {}

void Application::initServer() {
  _servers.push_back(Server());
}

void Application::SelectFds() {

}

#include "SelectHelper.hpp"

#include <fcntl.h>
#include <unistd.h>

fd_set SelectHelper::_read_fds;
fd_set SelectHelper::_write_fds;
fd_set SelectHelper::_error_fds;
std::vector<Client> SelectHelper::_clients;
std::vector<Server> SelectHelper::_servers;
int SelectHelper::_nfds = 3;

SelectHelper::SelectHelper() {
  FD_ZERO(&_read_fds);
  FD_ZERO(&_write_fds);
  FD_ZERO(&_error_fds);
}

SelectHelper::~SelectHelper() {}

void SelectHelper::addReadEvent(int fd) {
  FD_SET(fd, &_read_fds);
}

void SelectHelper::addWriteEvent(int fd) {
  FD_SET(fd, &_write_fds);
}

void SelectHelper::addErrorEvent(int fd) {
  FD_SET(fd, &_error_fds);
}

void SelectHelper::deleteReadfds(int fd) {
  FD_CLR(fd, &_read_fds);
}

void SelectHelper::deleteWritefds(int fd) {
  FD_CLR(fd, &_write_fds);
}

void SelectHelper::deleteErrorfds(int fd) {
  FD_CLR(fd, &_error_fds);
}

void SelectHelper::initServer() {
  _servers.push_back(Server());
  _nfds++;

  addReadEvent(_servers[0].getFd());
}

int SelectHelper::inspectFds() {
  int selected = select(_nfds, &_read_fds, &_write_fds, &_error_fds, NULL);
  int handled = 0;

  for (int i = 0; (i < _nfds) && (handled < selected); i++) {
    if (FD_ISSET(i, &_read_fds)) {
      if (i == _servers[0].getFd()) {
        Client accepted(accept(_servers[0].getFd(), NULL, NULL));

        if (accepted.getFd() == -1) {
          std::cout << "accept error" << std::endl;
          continue;
        }

        fcntl(accepted.getFd(), F_SETFL, O_NONBLOCK);
        std::cout << "client accepted: fd: " << accepted.getFd() << std::endl;

        _clients.push_back(accepted);
        FD_CLR(i, &_read_fds);
        FD_SET(i, &_read_fds);
        FD_SET(_clients[0].getFd(), &_read_fds);

        _nfds += accepted.getFd() >= _nfds;
      } else {
        char  buf[1025];
        ssize_t recved = recv(i, buf, 1024, 0);

        if (recved < 0) {
          std::cout << i << " error" << std::endl;
          close(i);
        } else if (recved == 0) {
          std::cout << "connection closed: fd: " << i << std::endl;
          close(i);
        } else {
          buf[recved] = 0;
          std::cout << "recved message: " << buf << std::endl;
        }
      }
    }
  }

  for (int i = 0; (i < _nfds) && (handled < selected); i++) {
    if (FD_ISSET(i, &_write_fds)) {

    }
  }

  for (int i = 0; (i < _nfds) && (handled < selected); i++) {
    if (FD_ISSET(i, &_error_fds)) {

    }
  }

  return 0;
}

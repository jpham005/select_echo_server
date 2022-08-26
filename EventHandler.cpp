#include "EventHandler.hpp"

#include <iostream>

#include <sys/socket.h>

EventHandler::EventHandler() {}

EventHandler::~EventHandler() {}

void EventHandler::handleReadEvent(int fd) {
  if (fd == 3) {// should save server fd

  }
}

void EventHandler::handleWriteEvent(int fd) {

}

void EventHandler::handleErrorEvent(int fd) {

}

void EventHandler::connectClient(int server) {
  int fd = accept(server, NULL, NULL);

  if (fd) {
    throw std::runtime_error("accept error");
  }

  std::cout << "client connected: fd: " << fd << std::endl;
}

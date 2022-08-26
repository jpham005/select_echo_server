#pragma once

class EventHandler {
private:
  EventHandler(const EventHandler& other);
  EventHandler& operator=(const EventHandler& other);

public:
  EventHandler();
  ~EventHandler();

  void handleReadEvent(int fd);
  void handleWriteEvent(int fd);
  void handleErrorEvent(int fd);

  void connectClient(int server);
};

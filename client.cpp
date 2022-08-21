#include <iostream>

#include <cstring>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

extern int errno;

int main() {
  int client;

  client = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_addr.s_addr = htonl(inet_addr("127.0.0.1"));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(9090);

  bind(client, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr));

  listen(client, 1024);

  memset(&addr, 0, sizeof(addr));
  addr.sin_addr.s_addr = htonl(inet_addr("127.0.0.1"));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);

  errno = 0;

  connect(client, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr));

  if (errno != 0)
    perror("connect");
  else
    std::cout << "connection success" << std::endl;
}

#include "Client.hpp"

Client::Client(int fd) : Socket(fd) {}

Client::Client(const Client &other) : Socket(other._fd) {}

Client::~Client() {}

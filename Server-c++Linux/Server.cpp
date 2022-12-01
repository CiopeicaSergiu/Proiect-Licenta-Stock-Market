#include "Server.h"
#include <iostream>

#include <algorithm>
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <fcntl.h>
#include <netinet/in.h> // For sockaddr_in
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For read

namespace utilities::conectivity {

// Create a socket (IPv4, TCP)
void Server::createSocket() {

  serverSocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocketDescriptor == -1) {
    std::cout << "Failed to create socket. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Server::createConfigureForSocket() {
  socketConfiguration.sin_family = AF_INET;
  socketConfiguration.sin_addr.s_addr = htonl(INADDR_ANY);
  socketConfiguration.sin_port = htons(port);
}

void Server::applyConfigurationToSocket() {
  if (bind(serverSocketDescriptor,
           reinterpret_cast<struct sockaddr *>(&socketConfiguration),
           sizeof(sockaddr)) < 0) {
    std::cout << "Failed to bind to port 2136. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Server::setNrClientLimit(const int maxClientsNumber) {
  if (listen(serverSocketDescriptor, maxClientsNumber) < 0) {
    std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Server::makeSocketNonBlocking() {

  const auto connectionFlag = fcntl(serverSocketDescriptor, F_GETFL);

  if (connectionFlag < 0) {
    std::cout << "could not get flags on TCP listening socket" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (fcntl(serverSocketDescriptor, F_SETFL, connectionFlag | O_NONBLOCK)) {
    std::cout << "could not set TCP listening socket to be non-blocking"
              << std::endl;
    exit(EXIT_FAILURE);
  }
}

Server::Server() {
  createSocket();
  makeSocketNonBlocking();
  createConfigureForSocket();
  applyConfigurationToSocket();
  setNrClientLimit(10);
}

Server::~Server() { close(serverSocketDescriptor); }

void Server::startServer() {

  while (true) {
    // Grab a connection from the queue
    // struct sockaddr_in socketConfigurationClient;
    // auto addrlen = sizeof(sockaddr);

    const auto connection = accept(serverSocketDescriptor, NULL, NULL);

    if (connection >= 0) {
      std::cout << "Connection enstablished" << std::endl;
      connectedClients.emplace_back(Client(connection));
    }
  }

  std::for_each(connectedClients.begin(), connectedClients.end(),
                [](auto &client) { client.joinClientThread(); });
}
} // namespace utilities::conectivity
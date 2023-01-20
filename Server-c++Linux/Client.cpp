#include "Client.h"
#include <cstring>
#include <iostream>
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For read

namespace utilities::conectivity {

void Client::startConnectionForClient() {
  std::string message{"Connection enstablished!"};
  sendMessage(message);
  bool isWarning = false;
  while (true) { // not isErrorEncountered(sendMessage(message))) {

    // if (not isWarning) {
    message = receiveMessage();
    //}

    // if (not message.empty()) {
    isWarning = isWarningEncountered(sendMessage(message));
    // }
    // std::cout << "Loop on connection: " << connectionIdentifier << std::endl;
  }

  std::cout << "Connection is closed!" << std::endl;
  close(connectionIdentifier);
}

bool Client::isErrorEncountered(const ssize_t status) { return status == -1; }

bool Client::isWarningEncountered(const ssize_t status) {
  return status == EWOULDBLOCK or status == EAGAIN;
}

std::string Client::receiveMessage() {

  const auto bufferSize = 100;
  char buffer[bufferSize];

  const auto bytesRead = read(connectionIdentifier, buffer, 100);
  std::cout << "Message received: " << buffer << std::endl;
  if (isErrorEncountered(bytesRead) || isWarningEncountered(bytesRead)) {
    return "";
  }
  // do {
  //   bytesRead = read(connectionIdentifier, buffer, 100);
  //   // I don`t like this it is pretty unsafe, I can brake it (:
  //   result += buffer;
  // } while (bytesRead > 0);

  return buffer;
}

ssize_t Client::sendMessage(const std::string &message) {

  return send(connectionIdentifier, message.c_str(), message.size() + 1, 0);
}

Client::Client(const int connIdt) : connectionIdentifier{connIdt} {
  std::cout << "Client communication connected!" << std::endl;
  clientThread = std::thread(&Client::startConnectionForClient, this);
  // clientThread.detach();
  //  startConnectionForClient();
}

void Client::joinClientThread() { clientThread.join(); }

} // namespace utilities::conectivity

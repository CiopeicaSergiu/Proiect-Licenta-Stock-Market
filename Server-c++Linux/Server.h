#include "Client.h"
#include <netinet/in.h> // For sockaddr_in
#include <vector>

namespace utilities::conectivity {
class Server {
private:
  // find a better name
  int serverSocketDescriptor;
  sockaddr_in socketConfiguration;
  const uint16_t port = 2136;
  std::vector<Client> connectedClients;

  void createSocket();
  void makeSocketNonBlocking();
  void createConfigureForSocket();
  void applyConfigurationToSocket();
  void setNrClientLimit(const int maxClientsNumber);

public:
  void startServer();
  Server();
  ~Server();
};
} // namespace utilities::conectivity
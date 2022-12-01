#include <string>
#include <thread>

namespace utilities::conectivity {
class Client {
private:
  const int connectionIdentifier;
  std::thread clientThread;
  bool isErrorEncountered(const ssize_t status);

public:
  explicit Client(const int connIdt);
  void startConnectionForClient();
  std::string receiveMessage();
  ssize_t sendMessage(const std::string &message);
  void joinClientThread();
};
} // namespace utilities::conectivity
#include <memory>
#include <restbed>

using Resources = std::vector<std::shared_ptr<restbed::Resource>>;

class Service {

protected:
  Resources resources;

private:
  restbed::Service service;
  std::shared_ptr<restbed::Settings> settings;
  const unsigned int port;

  virtual void setEndpoints() = 0;
  void setSettings();

public:
  Service(const unsigned int port = 1984);
  void start();
  void stop();
};
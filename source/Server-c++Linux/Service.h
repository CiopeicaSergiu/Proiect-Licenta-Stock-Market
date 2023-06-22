#include <memory>
#include <restbed>

class Service {

protected:
  std::shared_ptr<restbed::Resource> resource;

private:
  restbed::Service service;
  std::shared_ptr<restbed::Settings> settings;
  const unsigned int port;

  virtual void setEndpoints() = 0;
  void setSettings();

public:
  Service(const unsigned int port=1984);
  void start();
  void stop();
};
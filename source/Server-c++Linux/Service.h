#include <memory>
#include <restbed>

class Service {

protected:
  std::shared_ptr<restbed::Resource> resource;

private:
  restbed::Service service;
  std::shared_ptr<restbed::Settings> settings;
  const unsigned int port = 1984;

  virtual void setEndpoints() = 0;
  void setSettings();

public:
  Service();
  void start();
  void stop();
};
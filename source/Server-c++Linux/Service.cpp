#include "Service.h"
#include <memory>
#include <restbed>

Service::Service() {
  resource = std::make_shared<restbed::Resource>();
  settings = std::make_shared<restbed::Settings>();
}

void Service::setSettings() {
  settings->set_port(port);
  settings->set_default_header("Connection", "close");
}

void Service::start() {
  setEndpoints();
  setSettings();
  service.publish(resource);
  service.start(settings);
}

#include "Service.h"
#include <memory>
#include <restbed>

Service::Service(const unsigned int port) : port(port) {
  // resource = std::make_shared<restbed::Resource>();
  settings = std::make_shared<restbed::Settings>();
}

void Service::setSettings() {
  settings->set_port(port);
  settings->set_default_header("Connection", "close");
}

void Service::start() {
  setEndpoints();
  setSettings();

  for (const auto &resource : resources) {
    service.publish(resource);
  }

  service.start(settings);
}

void Service::sendResponseAndCloseSession(
    std::shared_ptr<restbed::Session> &session, const std::string &result) {
  session->close(restbed::OK, result,
                 {{"Content-Length", std::to_string(result.size()).c_str()},
                  {"Connection", "close"}});
}

void Service::sendUnfoundAndCloseSession(
    std::shared_ptr<restbed::Session> &session) {
  session->close(restbed::NOT_FOUND);
}
void Service::sendErrorMessageAndCloseSession(
    std::shared_ptr<restbed::Session> &session,
    const std::string errorMessage) {
  session->close(
      restbed::INTERNAL_SERVER_ERROR, errorMessage,
      {{"Content-Length", std::to_string(errorMessage.size()).c_str()},
       {"Connection", "close"}});
}
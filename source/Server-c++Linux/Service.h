#pragma once
#include <memory>
#include <restbed>

constexpr auto ONE_DAY = 86400;

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
  void sendResponseAndCloseSession(std::shared_ptr<restbed::Session> &session,
                                   const std::string &result);
  void sendUnfoundAndCloseSession(std::shared_ptr<restbed::Session> &session);
  void
  sendErrorMessageAndCloseSession(std::shared_ptr<restbed::Session> &session,
                                  const std::string errorMessage);

  Service(const unsigned int port = 1984);
  void start();
  void stop();
};
#pragma once
#include "Service.h"

class PriceService : public Service {

public:
  PriceService() : Service(2000) {}

private:
  void setEndpoints() override;

  void setEventGeneratePrice();

  void eventGeneratePrice(std::shared_ptr<restbed::Session> session);
};

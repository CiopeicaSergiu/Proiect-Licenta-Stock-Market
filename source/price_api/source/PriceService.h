#pragma once
#include "Service.h"

class PriceService : public Service {

private:
  void setEndpoints() override;

  void setEventGeneratePrice();

  void eventGeneratePrice(std::shared_ptr<restbed::Session> session);
};

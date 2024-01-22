#pragma once
#include "/home/sergiu/Desktop/Licenta/source/Server-c++Linux/Service.h"

class PriceService : public Service {

private:
  void setEndpoints() override;

  void setEventGeneratePrice();

  void eventGeneratePrice(std::shared_ptr<restbed::Session> session);
};

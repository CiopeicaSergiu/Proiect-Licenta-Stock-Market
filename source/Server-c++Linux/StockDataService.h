#include "Service.h"

class StockDataService : public Service {
private:

  void sendResponseAndCloseSession( std::shared_ptr<restbed::Session>& session, const std::string& result);

  void setEventGetStockData(std::shared_ptr<restbed::Resource> &resource);

  void eventGetStockData(std::shared_ptr<restbed::Session> session);

  void setEndpoints() override;
};
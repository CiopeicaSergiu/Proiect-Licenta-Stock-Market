#include "Service.h"

class StockDataService : public Service {
private:
  // void sendResponseAndCloseSession(std::shared_ptr<restbed::Session>
  // &session,
  //                                  const std::string &result);
  // void sendUnfoundAndCloseSession(std::shared_ptr<restbed::Session>
  // &session); void
  // sendErrorMessageAndCloseSession(std::shared_ptr<restbed::Session> &session,
  //                                 const std::string errorMessage);

  void setEventGetStockData();
  void setEventLogin();
  void setEventTest();

  void eventGetStockData(std::shared_ptr<restbed::Session> session);
  void eventLogin(std::shared_ptr<restbed::Session> session,
                  const restbed::Bytes &body);
  void eventBuyCommand(std::shared_ptr<restbed::Session> session,
                       const restbed::Bytes &body);

  void setEndpoints() override;
};
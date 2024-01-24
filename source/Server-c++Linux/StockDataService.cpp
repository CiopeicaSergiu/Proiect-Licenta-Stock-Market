#include "StockDataService.h"
#include "../converter/TimeConverter.h"
#include "../data/StockData.h"
#include "../formatter/DataFormater.h"
#include "../formatter/parsing.h"
#include "../request/RequestStockData.h"
#include <ctime>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iomanip>
#include <restbed>
#include <sstream>

#include "RequestToPriceApi.h"
#include "Serialize.h"
#include "SqlExecutor.h"
#include "SqlGenerator.h"
#include "Utils.h"
#include "model/BidAskPrice.h"
#include "model/Credentials.h"
#include <boost/json/serialize.hpp>
#include <boost/json/value_to.hpp>
#include <fmt/core.h>
#include <iostream>

using namespace stockService;

void StockDataService::setEventGetStockData() {
  resources.emplace_back(std::make_shared<restbed::Resource>());
  resources.back()->set_path("/{stockName: ^[a-z]{4}}");
  resources.back()->set_method_handler(
      "GET", [this](std::shared_ptr<restbed::Session> session) {
        eventGetStockData(session);
      });
}

void StockDataService::setEventTest() {
  resources.emplace_back(std::make_shared<restbed::Resource>());
  resources.back()->set_path("/test");
  resources.back()->set_method_handler(
      "GET", [this](std::shared_ptr<restbed::Session> session) {
        sendResponseAndCloseSession(session, "Hello from test!");
      });
}

void StockDataService::setEventLogin() {
  resources.emplace_back(std::make_shared<restbed::Resource>());
  resources.back()->set_path("/login");
  resources.back()->set_method_handler(
      "POST", [this](std::shared_ptr<restbed::Session> session) {
        session->fetch(
            session->get_request()->get_header("Content-Length", 0),
            [this](const std::shared_ptr<restbed::Session> session,
                   const restbed::Bytes &body) { eventLogin(session, body); });
      });
}

void StockDataService::setEventBuyCommand() {
  resources.emplace_back(std::make_shared<restbed::Resource>());
  resources.back()->set_path("/buy");
  resources.back()->set_method_handler(
      "POST", [this](std::shared_ptr<restbed::Session> session) {
        session->fetch(session->get_request()->get_header("Content-Length", 0),
                       [this](const std::shared_ptr<restbed::Session> session,
                              const restbed::Bytes &body) {
                         eventBuyCommand(session, body);
                       });
      });
}

void StockDataService::eventGetStockData(
    std::shared_ptr<restbed::Session> session) {
  std::cout << "eventGetStockData triggered!!\n";
  const auto request = session->get_request();

  const auto stockName = request->get_path_parameter("stockName");
  const auto startTime = request->get_query_parameter("startTime");
  const auto endTime = request->get_query_parameter("endTime");

  curlpp::Cleanup myCleanup;
  RequestStockData requestGoogle(stockName);

  // const uint64_t start = 1641059569;
  // const uint64_t stop = 1641579977;
  const auto startTimeUnix =
      converter::dateTime::dateToUnixTimeShortFormat(startTime);

  const auto endTimeUnix =
      converter::dateTime::dateToUnixTimeShortFormat(endTime);

  auto data = requestGoogle.requestStockData(startTimeUnix,
                                             endTimeUnix + ONE_DAY, "1d");

  auto stocksData = parsing::parseStockData(data);

  std::cout << stocksData.front();

  auto formater = DataFormater();
  const std::string result =
      formater.formatData(stocksData, formatingType::csv);

  sendResponseAndCloseSession(session, result);
}

void StockDataService::eventLogin(std::shared_ptr<restbed::Session> session,
                                  const restbed::Bytes &body) {
  std::cout << "eventLogin triggered!!\n";

  const Json::value jsonValue = utils::toBoostValue(utils::to_string(body));
  Credentials credentials = Json::value_to<Credentials>(jsonValue);

  const std::string stringToSend = Json::serialize(jsonValue);

  utils::SubTable queryTable({"id", "username", "pass"});

  {
    utils::SqlExecutor sqlExecutor({"licenta", "password"},
                                   {"localhost", 3306, "licenta"});

    sqlExecutor.executeStatement(
        fmt::format(
            "select * from users where username=\"{}\" and pass=\"{}\";",
            credentials.username, credentials.password),
        queryTable);
  }

  if (not queryTable.entries.empty()) {
    sendResponseAndCloseSession(session, "Loged in succesfully");
  } else {
    sendUnfoundAndCloseSession(session);
  }
}

void StockDataService::eventBuyCommand(
    std::shared_ptr<restbed::Session> session, const restbed::Bytes &body) {

  const Json::value jsonValue = utils::toBoostValue(utils::to_string(body));

  const auto bidAskPrice = Json::value_to<BidAskPrice>(jsonValue);

  utils::SubTable queryTable;

  {
    utils::SqlGenerator sqlGenerator("./database_licenta/buy.txt");
    utils::SqlExecutor sqlExecutor({"licenta", "password"},
                                   {"localhost", 3306, "licenta"});
    std::cout << "SQL statement: "
              << sqlGenerator.prepareStatement<utils::Operations::insert>(
                     bidAskPrice.stockName, bidAskPrice.quantity,
                     bidAskPrice.price)
              << "\n";

    sqlExecutor.executeStatement(
        sqlGenerator.prepareStatement<utils::Operations::insert>(
            bidAskPrice.stockName, bidAskPrice.quantity, bidAskPrice.price),
        queryTable);
    std::cout << "HelloWorld from buy command! 2\n";

    sqlExecutor.executeStatement("commit;");
  }

  RequestToPriceApi requestToPriceApi{bidAskPrice.stockName};

  const auto askPriceForStock =
      requestToPriceApi(bidAskPrice.stockName, bidAskPrice.quantity);

  if (not askPriceForStock.empty()) {
    sendResponseAndCloseSession(session, askPriceForStock);
  } else {
    sendUnfoundAndCloseSession(session);
  }
}

void StockDataService::setEndpoints() {
  setEventGetStockData();
  setEventLogin();
  setEventTest();
  setEventBuyCommand();
}

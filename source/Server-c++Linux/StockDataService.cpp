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

#include <iostream>

void StockDataService::setEventGetStockData(
    std::shared_ptr<restbed::Resource> &resource) {
  resource->set_path("/");
  resource->set_method_handler(
      "GET", [this](std::shared_ptr<restbed::Session> session) {
        eventGetStockData(session);
      });
}

void StockDataService::eventGetStockData(
    std::shared_ptr<restbed::Session> session) {

  curlpp::Cleanup myCleanup;
  // Send request and get a result.
  // Here I use a shortcut to get it in a string stream ...
  RequestStockData requestGoogle("goog");

  const uint64_t start = 1641059569;
  const uint64_t stop = 1641579977;

  std::cout << "start: " << converter::dateTime::unixTimeToDate(start) << "\n";
  std::cout << "stop: " << converter::dateTime::unixTimeToDate(stop) << "\n";

  auto data = requestGoogle.requestStockData(start, stop, "1d");
  auto stocksData = parsing::parseStockData(data);

  auto formater = DataFormater();

  const std::string result =
      formater.formatData(stocksData, formatingType::table);
  session->close(restbed::OK, result,
                 {{"Content-Length", std::to_string(result.size()).c_str()},
                  {"Connection", "close"}});
}

void StockDataService::setEndpoints() { setEventGetStockData(resource); }

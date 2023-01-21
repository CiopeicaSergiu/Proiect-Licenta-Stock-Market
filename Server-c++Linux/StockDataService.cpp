#include "StockDataService.h"
#include "../converter/TimeConverter.h"
#include "../data/StockData.h"
#include "../formatter/DataFormater.h"
#include "../formatter/parsing.h"
#include <ctime>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iomanip>
#include <restbed>
#include <sstream>

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
  std::string urlStrig{"https://query1.finance.yahoo.com/v7/finance/download/"
                       "goog?period1=1641059569&period2=1641579977&interval=1d&"
                       "includeAdjustedClose=true"};

  std::ostringstream osBuffer;
  osBuffer << curlpp::options::Url(urlStrig);

  const auto information = osBuffer.str();
  auto stocksData = parsing::parseStockData(information);
  auto formater = DataFormater();
  std::string result = formater.formatData(stocksData, formatingType::table);

  session->close(restbed::OK, result,
                 {{"Content-Length", std::to_string(result.size()).c_str()},
                  {"Connection", "close"}});
}

void StockDataService::setEndpoints() { setEventGetStockData(resource); }

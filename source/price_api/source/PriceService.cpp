#include "PriceService.h"
#include "DataFormater.h"
#include "PriceGenerator.h"
#include "RequestStockData.h"
#include "Serialize.h"
#include "TimeConverter.h"
#include "model/BidAskPrice.h"
#include "parsing.h"
#include <boost/json/serialize.hpp>
#include <boost/json/value_to.hpp>
#include <ctime>
#include <iostream>

using namespace stockService;

void PriceService::eventGeneratePrice(
    std::shared_ptr<restbed::Session> session) {

  const auto request = session->get_request();

  const auto stockName = request->get_path_parameter("stockName");
  const auto quantity = request->get_query_parameter("quantity");

  RequestStockData requestGoogle(stockName);

  // const uint64_t start = 1641059569;
  // const uint64_t stop = 1641579977;

  time_t secondsUntilNow = time(0);

  const std::string date = converter::dateTime::unixTimeToDate(secondsUntilNow);

  std::string data;
  std::string possibleStatus;
  int maximumRetries = 5;

  do {
    data = requestGoogle.requestStockData(secondsUntilNow,
                                          secondsUntilNow + ONE_DAY, "1d");
    possibleStatus = data.substr(0, 3);

    if (possibleStatus == "404") {
      secondsUntilNow -= ONE_DAY;
    }

  } while (--maximumRetries);

  auto stocksData = parsing::parseStockData(data);

  auto formater = DataFormater();
  const std::string result =
      formater.formatData(stocksData, formatingType::csv);

  BidAskPrice bidAskPrice;
  bidAskPrice.price =
      std::stoul(quantity) *
      priceGenerator::generateBuyCostNormalDistribution(
          std::stod(stocksData.front().getElement(dataElement::close)));

  std::cout << "Something: " << bidAskPrice.price;
  bidAskPrice.stockName = stockName;
  bidAskPrice.quantity = std::stoul(quantity);

  sendResponseAndCloseSession(session,
                              Json::serialize(Json::value_from(bidAskPrice)));
}

void PriceService::setEndpoints() { setEventGeneratePrice(); }

void PriceService::setEventGeneratePrice() {
  resources.emplace_back(std::make_shared<restbed::Resource>());
  resources.back()->set_path("/{stockName: ^[a-z]{4}}");
  resources.back()->set_method_handler(
      "GET", [this](std::shared_ptr<restbed::Session> session) {
        eventGeneratePrice(session);
      });
}

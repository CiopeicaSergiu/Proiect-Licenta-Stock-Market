#include "PriceService.h"
#include "RequestStockData.h"
#include "TimeConverter.h"
#include "parsing.h"
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

void PriceService::eventGeneratePrice(
    std::shared_ptr<restbed::Session> session) {

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

  auto formater = DataFormater();
  const std::string result =
      formater.formatData(stocksData, formatingType::csv);

  sendResponseAndCloseSession(session, result);
}
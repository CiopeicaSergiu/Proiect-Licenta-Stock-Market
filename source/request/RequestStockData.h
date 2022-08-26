#pragma once
#include "formatter/DataFormater.h"
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <sstream>
#include <string>
class RequestStockData {
private:
  std::string url{"https://query1.finance.yahoo.com/v7/finance/download/"
                  "{}?period1={}&period2={}&interval={}&"
                  "includeAdjustedClose=true"};
  auto requestStockData(std::uint64_t start, std::uint64_t stop,
                        const std::string &step) -> std::string;

public:
  RequestStockData(std::string stockName);
};
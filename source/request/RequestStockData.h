#pragma once
#include <sstream>
#include <string>
class RequestStockData {
private:
  std::string url{"https://query1.finance.yahoo.com/v7/finance/download/"
                  "{}?period1={}&period2={}&interval={}&"
                  "includeAdjustedClose=true"};

public:
  explicit RequestStockData(std::string stockName);
  auto requestStockData(std::uint64_t start, std::uint64_t stop,
                        std::string step) -> std::string;
};

// uses curlpp, boost
#include "formatter/DataFormater.h"
#include "formatter/parsing.h"
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iostream>
#include <sstream>
int main() {
  // RAII cleanup

  curlpp::Cleanup myCleanup;

  // Send request and get a result.
  // Here I use a shortcut to get it in a string stream ...
  std::string urlStrig{"https://query1.finance.yahoo.com/v7/finance/download/"
                       "goog?period1=1641059569&period2=1641579977&interval=1d&"
                       "includeAdjustedClose=true"};

  std::ostringstream osBuffer;
  osBuffer << curlpp::options::Url(urlStrig);

  const auto information = osBuffer.str();
  std::cout << information << std::endl;
  const auto stocksData = parsing::parseStockData(information);
  auto formater = DataFormater();
  std::cout << formater.formatData(stocksData, formatingType::table);
  return 0;
}

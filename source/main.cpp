
// uses curlpp, boost
#include "converter/TimeConverter.h"
#include "formatter/DataFormater.h"
#include "formatter/parsing.h"
#include <ctime>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iostream>
#include <sstream>

using namespace converter::dateTime;
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
  std::time_t result = std::time(nullptr);

  auto date1 = std::asctime(std::localtime(&result));
  auto unixTime2 = dateToUnixTime(date1);
  auto date2 = std::asctime(std::localtime(&unixTime2));
  std::cout << date1 << result << std::endl << date2 << unixTime2 << std::endl;
  return 0;
}

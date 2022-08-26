#include "parsing.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iterator>
#include <stdexcept>

auto parsing::parseStockData(std::string stringData) -> std::vector<StockData> {

  auto splitAfter = std::string{"\r\n"};

  auto pos = stringData.find('\r');

  if (pos == std::string::npos) {
    pos = stringData.find('\n');
    if (pos == std::string::npos) {
      throw std::runtime_error{"Format not suported"};
    }
    splitAfter = "\n";
  }

  std::vector<std::string> splitedData;
  boost::split(splitedData, stringData, boost::is_any_of(splitAfter));

  if (splitedData.size() < 2) {
    throw std::runtime_error{"Format not suported"};
  }

  std::vector<StockData> result;
  std::transform(std::next(splitedData.begin()), splitedData.end(),
                 std::back_inserter(result),
                 [](const auto &str) { return StockData(str); });
  return result;
}
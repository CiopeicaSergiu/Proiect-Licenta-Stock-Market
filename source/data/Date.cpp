#include "Date.h"
#include <boost/algorithm/string.hpp>
#include <stdexcept>
#include <vector>

Date::Date(const std::string &date) {
  std::vector<std::string> result;
  boost::split(result, date, boost::is_any_of("-"));

  if (result.size() != 3) {
    throw std::runtime_error{"The date is not in a valide format."};
  }

  year = std::stoi(result[2]);
  month = std::stoi(result[1]);
  day = std::stoi(result[0]);
}

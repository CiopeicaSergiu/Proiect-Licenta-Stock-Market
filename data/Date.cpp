#include "Date.h"
#include "../converter/TimeConverter.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fmt/format.h>
#include <map>
#include <stdexcept>
#include <vector>

Date::Date(const std::string &dateInput) : unixTimeStamp{0} {
  date = formatDate(dateInput);
}

std::string Date::formatDate(const std::string &dateInput) {
  static const std::map<std::string, size_t> months = {
      {"Jan", 0}, {"Feb", 1}, {"Mar", 2}, {"Apr", 3}, {"May", 4},  {"Jun", 5},
      {"Jul", 6}, {"Aug", 7}, {"Sep", 8}, {"Oct", 9}, {"Nov", 10}, {"Dec", 11}};

  std::vector<std::string> splitedInput;

  splitedInput.reserve(3);

  boost::split(splitedInput, dateInput, boost::is_any_of("-"));

  if (splitedInput.size() != 3) {
    throw std::runtime_error{"Date not formated properly!"};
  }

  auto year = std::stoi(splitedInput[0]);
  auto month = std::stoi(splitedInput[1]) - 1;
  auto day = std::stoi(splitedInput[2]);

  const auto itMonth =
      std::find_if(months.begin(), months.end(),
                   [&](const auto &it) { return it.second == month; });

  if (itMonth == months.end()) {
    throw std::runtime_error{"Date not formated properly!"};
  }

  std::string dateTamplate{"None {} {:>2} 08:00:00 {}"};

  auto buffer = fmt::memory_buffer{};

  fmt::format_to(std::back_inserter(buffer), dateTamplate, itMonth->first, day,
                 year);

  return converter::dateTime::unixTimeToDate(
      converter::dateTime::dateToUnixTime(fmt::to_string(buffer)));
}

long Date::getUnixTimeStamp() {
  if (not unixTimeStamp) {
    unixTimeStamp = converter::dateTime::dateToUnixTime(date);
  }
  return unixTimeStamp;
}

std::string Date::getDate() {
  if (date.empty()) {
    date = converter::dateTime::unixTimeToDate(unixTimeStamp);
  }
  return date;
}

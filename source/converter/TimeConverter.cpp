#include "TimeConverter.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <ctime>
#include <map>
#include <stdexcept>

auto converter::dateTime::unixTimeToDate(time_t unixTime) -> std::string {
  setenv("TZ", "", 1);
  return std::asctime(std::localtime(&unixTime));
}

auto converter::dateTime::dateToUnixTime(const std::string &date) -> time_t {

  setenv("TZ", "", 1);
  std::tm timeinfo{};

  std::map<std::string, size_t> months = {
      {"Jan", 0}, {"Feb", 1}, {"Mar", 2}, {"Apr", 3}, {"May", 4},  {"Jun", 5},
      {"Jul", 6}, {"Aug", 7}, {"Sep", 8}, {"Oct", 9}, {"Nov", 10}, {"Dec", 11}};

  std::vector<std::string> splitedDate;
  boost::split(splitedDate, date, boost::is_any_of(" :"));

  if (splitedDate.size() != 7) {
    throw std::runtime_error{"The date is not formatted properly!"};
  }

  const auto itMonths = months.find(splitedDate[1]);

  if (itMonths == months.end()) {
    throw std::runtime_error{"The date is not formatted properly!"};
  }

  int year = std::stoi(splitedDate[6]);
  int month = itMonths->second;
  int day = std::stoi(splitedDate[2]);

  int hour = std::stoi(splitedDate[3]);
  int min = std::stoi(splitedDate[4]);
  int sec = std::stoi(splitedDate[5]);

  timeinfo.tm_year = year - 1900;
  timeinfo.tm_mon = month;
  timeinfo.tm_mday = day;
  timeinfo.tm_hour = hour;
  timeinfo.tm_min = min;
  timeinfo.tm_sec = sec;
  timeinfo.tm_isdst = 0;

  return mktime(&timeinfo);
}
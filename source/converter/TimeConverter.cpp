#include "TimeConverter.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <ctime>
#include <iostream>
#include <map>
#include <stdexcept>

constexpr int REPORTING_STARTING_HOUR = 8;
constexpr int REPORTING_STARTING_MINUTE = 0;
constexpr int REPORTING_STARTING_SECOND = 0;
constexpr int UNIX_TIME_STARTING_POINT = 1900;

auto converter::dateTime::unixTimeToDate(time_t unixTime) -> std::string {
  setenv("TZ", "", 1);
  std::string date = std::asctime(std::localtime(&unixTime));
  return date.substr(0, date.size() - 1);
}

auto converter::dateTime::dateToUnixTime(std::string date) -> time_t {
  setenv("TZ", "", 1);
  std::tm timeinfo{};

  static const std::map<std::string, size_t> months = {
      {"Jan", 0}, {"Feb", 1}, {"Mar", 2}, {"Apr", 3}, {"May", 4},  {"Jun", 5},
      {"Jul", 6}, {"Aug", 7}, {"Sep", 8}, {"Oct", 9}, {"Nov", 10}, {"Dec", 11}};

  const auto posDoubleSpace = date.find("  ");

  if (posDoubleSpace != std::string::npos) {
    date.erase(posDoubleSpace, 1);
  }

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

time_t converter::dateTime::dateToUnixTimeShortFormat(const std::string &date,
                                                      const char separator) {
  if (date.empty()) {
    throw std::runtime_error{"date is missing!"};
  }

  setenv("TZ", "", 1);
  std::tm timeinfo{};

  std::vector<std::string> dateComponents;
  boost::split(dateComponents, date, boost::is_any_of("."));

  if (dateComponents.size() != 3) {
    std::cout << "dateComponents: " << dateComponents.front() << "\n";
    throw std::runtime_error{"The date is not formatted properly!"};
  }

  timeinfo.tm_year = std::stoi(dateComponents[2]) - UNIX_TIME_STARTING_POINT;
  timeinfo.tm_mon = std::stoi(dateComponents[1]) - 1;
  timeinfo.tm_mday = std::stoi(dateComponents[0]);
  timeinfo.tm_hour = REPORTING_STARTING_HOUR;
  timeinfo.tm_min = REPORTING_STARTING_MINUTE;
  timeinfo.tm_sec = REPORTING_STARTING_SECOND;
  timeinfo.tm_isdst = 0;

  return mktime(&timeinfo);
}

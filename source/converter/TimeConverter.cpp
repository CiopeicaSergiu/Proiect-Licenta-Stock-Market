#include "TimeConverter.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <map>
#include <stdexcept>
#include <time.h>

auto converter::dateTime::unixTimeToDate(time_t unixTime) -> std::string {
  return "";
}

auto converter::dateTime::dateToUnixTime(const std::string &date) -> time_t {

  time_t rawtime;
  struct tm *timeinfo;

  std::map<std::string, size_t> days = {{"Sun", 0}, {"Mon", 1}, {"Tue", 2},
                                        {"Wed", 3}, {"Thu", 4}, {"Fri", 5},
                                        {"Sat", 6}};

  std::map<std::string, size_t> months = {
      {"Jan", 0}, {"Feb", 1}, {"Mar", 2}, {"Apr", 3}, {"May", 4},  {"Jun", 5},
      {"Jul", 6}, {"Aug", 7}, {"Sep", 8}, {"Oct", 9}, {"Nov", 10}, {"Dec", 11}};

  std::vector<std::string> splitedDate;
  boost::split(splitedDate, date, boost::is_any_of(" :"));

  if (splitedDate.size() != 7) {
    throw std::runtime_error{"The date is not formatted properly!"};
  }

  const auto itDays = days.find(splitedDate[0]);

  if (itDays == days.end()) {
    throw std::runtime_error{"The date is not formatted properly!"};
  }

  const auto itMonths = months.find(splitedDate[1]);

  if (itMonths == months.end()) {
    throw std::runtime_error{"The date is not formatted properly!"};
  }

  int year = std::stoi(splitedDate[6]);
  int month = itMonths->second;
  int day = itDays->second;

  int hour = std::stoi(splitedDate[3]);
  int min = std::stoi(splitedDate[4]);
  int sec = std::stoi(splitedDate[5]);

  /* get current timeinfo: */
  time(&rawtime); // or: rawtime = time(0);
  /* convert to struct: */
  timeinfo = localtime(&rawtime);

  /* now modify the timeinfo to the given date: */
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month; // months since January - [0,11]
  timeinfo->tm_mday = day;  // day of the month - [1,31]
  timeinfo->tm_hour = hour; // hours since midnight - [0,23]
  timeinfo->tm_min = min;   // minutes after the hour - [0,59]
  timeinfo->tm_sec = sec;   // seconds after the minute - [0,59]

  /* call mktime: create unix time stamp from timeinfo struct */
  return mktime(timeinfo);
}
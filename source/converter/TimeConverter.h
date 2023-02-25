#pragma once
#include <string>

namespace converter::dateTime {
typedef long time_t;
auto unixTimeToDate(time_t unixTime) -> std::string;
auto dateToUnixTime(std::string date) -> time_t;
time_t dateToUnixTimeShortFormat(const std::string &date,
                                 const char separator = '.');
} // namespace converter::dateTime
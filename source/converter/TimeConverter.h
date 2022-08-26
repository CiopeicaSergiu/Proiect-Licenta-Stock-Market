#pragma once
#include <string>

namespace converter::dateTime {
typedef long time_t;
auto unixTimeToDate(time_t unixTime) -> std::string;
auto dateToUnixTime(const std::string &date) -> time_t;
} // namespace converter::dateTime
#pragma once
#include <string>

class Date {
private:
  long unixTimeStamp;
  std::string date;
  std::string formatDate(const std::string &str);

public:
  Date(const std::string &dateInput);
  Date(long unixTime) : unixTimeStamp{unixTime} {};
  Date() : date{}, unixTimeStamp{0} {};
  // YYYY-MM-DD -> template

  long getUnixTimeStamp();
  std::string getDate();
  std::string getDateShortFormat();
};
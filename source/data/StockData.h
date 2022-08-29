#pragma once
#include "Date.h"
#include <map>
#include <string>

enum class dataElement { date, open, high, low, adjClose, close, volume };

class StockData {
private:
  static const std::map<std::string, size_t> months;
  Date date;
  std::string open;
  std::string high;
  std::string low;
  std::string close;
  std::string adjClose;
  std::string volume;

public:
  StockData(const std::string &data);
  auto getElement(dataElement element) -> std::string;
};
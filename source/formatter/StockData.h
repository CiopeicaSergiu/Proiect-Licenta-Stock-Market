#pragma once
#include <string>

enum class dataElement { date, open, high, low, adjClose, close, volume };

class StockData {
private:
  std::string date;
  std::string open;
  std::string high;
  std::string low;
  std::string close;
  std::string adjClose;
  std::string volume;

public:
  StockData(const std::string &data);
  auto getElement(dataElement element) const -> std::string;
};
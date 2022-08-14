#pragma once
#include <string>

enum class dataElement { date, open, low, adj, close, volume };

class StockData {
private:
  std::string date;
  std::string open;
  std::string low;
  std::string adj;
  std::string close;
  std::string volume;

public:
  StockData(const std::string &data);
  auto getElement(dataElement element) const -> std::string;
};
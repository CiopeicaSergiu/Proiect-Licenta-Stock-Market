#pragma once
#include "Date.h"
#include <map>
#include <string>

enum class dataElement { date, open, high, low, adjClose, close, volume };

class StockData {
private:
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
  friend std::ostream &operator<<(std::ostream &os, StockData &stockData);
};

std::ostream &operator<<(std::ostream &os, StockData &stockData);
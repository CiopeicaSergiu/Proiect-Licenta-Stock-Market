#pragma once
#include "../data/StockData.h"
#include <string>
#include <utility>
#include <vector>

enum class formatingType { csv, table };

class DataFormater {
private:
  auto getHeaderFormat(formatingType typeOfFormating) -> std::string;
  auto getRowFormat(formatingType typeOfFormating) -> std::string;

public:
  auto formatData(std::vector<StockData> &stockDataArray, formatingType type)
      -> std::string;
};

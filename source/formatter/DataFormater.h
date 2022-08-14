#pragma once
#include "StockData.h"
#include <string>
#include <utility>
#include <vector>

enum class formatingType { csv, table };

class DataFormater {
private:
  auto getHeaderFormat(formatingType typeOfFormating) -> std::string;
  auto getRowFormat(formatingType typeOfFormating) -> std::string;

public:
  auto formatData(const std::vector<StockData> &stockDataArray,
                  formatingType type) -> std::string;
};

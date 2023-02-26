#pragma once
#include "../data/StockData.h"
#include <string>
#include <utility>
#include <vector>

enum class formatingType { csv, browser, client };

class DataFormater {
private:
  std::string getHeaderFormat(formatingType typeOfFormating);
  std::string getRowFormat(formatingType typeOfFormating);

public:
  std::string formatData(std::vector<StockData> &stockDataArray,
                         formatingType type);
};

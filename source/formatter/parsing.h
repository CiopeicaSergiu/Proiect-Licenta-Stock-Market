#pragma once
#include "StockData.h"
#include <string>
#include <vector>

namespace parsing {
auto parseStockData(std::string stringData) -> std::vector<StockData>;
}
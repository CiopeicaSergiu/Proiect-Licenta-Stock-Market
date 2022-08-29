#pragma once
#include "../data/StockData.h"
#include <string>
#include <vector>

namespace parsing {
auto parseStockData(std::string stringData) -> std::vector<StockData>;
}
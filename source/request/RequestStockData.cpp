// 1m 2m 5m 15m 30m 60m 90m 1h 1d 5d 1wk 1mo 3mo
#include "RequestStockData.h"
#include <fmt/core.h>
#include <fmt/format.h>

RequestStockData::RequestStockData(std::string stockName) {
  auto buffer = fmt::memory_buffer{};
  fmt::format_to(std::back_inserter(buffer), url, stockName);
  url = fmt::to_string(buffer);
}

auto RequestStockData::requestStockData(std::uint64_t start, std::uint64_t stop,
                                        std::string step) -> std::string {

  std::string stepPosibilities{"1m 2m 5m 15m 30m 60m 90m 1h 1d 5d 1wk 1mo 3mo"};

  const auto pos = stepPosibilities.find(step);

  if (pos == std::string::npos) {
    step = "1d";
  }

  auto buffer = fmt::memory_buffer{};
  fmt::format_to(std::back_inserter(buffer), url, start, stop, step);
  std::ostringstream osBuffer;
  osBuffer << curlpp::options::Url(fmt::to_string(buffer));

  return osBuffer.str();
}

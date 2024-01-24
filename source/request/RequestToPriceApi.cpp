#include "RequestToPriceApi.h"
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <exception>
#include <fmt/core.h>
#include <fmt/format.h>
#include <iostream>
#include <sstream>

RequestToPriceApi::RequestToPriceApi(const std::string_view stockName,
                                     const unsigned int portNumber) {
  auto buffer = fmt::memory_buffer{};
  try {
    fmt::format_to(std::back_inserter(buffer), url, stockName, portNumber, "{}",
                   "{}");
  } catch (const std::exception &e) {
    std::cout << "RequestStockData:RequestStockData eroare fmtlib."
              << std::endl;
  }

  url = fmt::to_string(buffer);
}

std::string RequestToPriceApi::operator()(const std::string_view stockName,
                                          const std::uint32_t quantity) {

  auto buffer = fmt::memory_buffer{};
  fmt::format_to(std::back_inserter(buffer), url, stockName, quantity);
  std::ostringstream osBuffer;
  curlpp::Cleanup myCleanup;
  osBuffer << curlpp::options::Url(fmt::to_string(buffer));

  return osBuffer.str();
}

#include "DataFormater.h"
#include <algorithm>
#include <fmt/core.h>
#include <fmt/format.h>
#include <vector>

auto DataFormater::getHeaderFormat(formatingType typeOfFormating)
    -> std::string {
  switch (typeOfFormating) {
  case formatingType::csv:
    return "Date,Open,High,Low,Close,Adj Close,Volume\n";
  default:
    return "-----------------------------------------------------"
           "-------------------------------------------------------------------"
           "-----------"
           "\n"
           "| Date                      | Open           | High           | "
           "Low "
           "          "
           " | Close          | Adj Close      | Volume         "
           "|\n----------------------------------------------------------------"
           "------------------------------------------------------------------"
           "\n";
  }
}

auto DataFormater::getRowFormat(formatingType typeOfFormating) -> std::string {
  switch (typeOfFormating) {
  case formatingType::csv:
    return "{},{},{},{},{},{}";
  default:
    return "| {:<25} | {:<14} | {:<14} | {:<14} | {:<14} | {:<14} | {:<14} |\n"
           "-------------------------------------------------------------------"
           "----------------------------------------------------------------\n";
  }
}

auto DataFormater::formatData(std::vector<StockData> &stockDataArray,
                              formatingType type) -> std::string {

  auto buffer = fmt::memory_buffer{};
  const auto itBuffer = std::back_inserter(buffer);

  const auto headerFormat = getHeaderFormat(type);
  const auto rowFormat = getRowFormat(type);

  fmt::format_to(itBuffer, headerFormat);
  std::for_each(stockDataArray.begin(), stockDataArray.end(),
                [&](auto &stockData) {
                  fmt::format_to(itBuffer, rowFormat,
                                 stockData.getElement(dataElement::date),
                                 stockData.getElement(dataElement::open),
                                 stockData.getElement(dataElement::high),
                                 stockData.getElement(dataElement::low),
                                 stockData.getElement(dataElement::adjClose),
                                 stockData.getElement(dataElement::close),
                                 stockData.getElement(dataElement::volume));
                });

  return fmt::to_string(buffer);
}
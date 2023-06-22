#include "DataFormater.h"
#include <algorithm>
#include <fmt/core.h>
#include <fmt/format.h>
#include <vector>

std::string DataFormater::getHeaderFormat(formatingType typeOfFormating) {
  switch (typeOfFormating) {
  case formatingType::browser:
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
  case formatingType::client:
    return "-------------------------------------------------------------------"
           "--------------------------------------------------------------\r\n"
           "| Date                                    | Open              | "
           "High   "
           "             | "
           "Low                | Close               | Adj Close       |    "
           "Volume  "
           "      "
           " "
           "|\r\n";
  default:
    return "";
  }
}

std::string DataFormater::getRowFormat(formatingType typeOfFormating) {
  switch (typeOfFormating) {
  case formatingType::csv:
    return "{},{},{},{},{},{},{}\n";
  case formatingType::browser:
    return "| {:<25} | {:<14} | {:<14} | {:<14} | {:<14} | {:<14} | {:<14} |\n"
           "-------------------------------------------------------------------"
           "----------------------------------------------------------------\n";
  case formatingType::client:
    return "| {:<30}   | {:<14} | {:<14} | {:<14} | {:<14} | {:<14} | {:<14} "
           "|\r\n"
           "-------------------------------------------------------------------"
           "--------------------------------------------------------------"
           "\r\n";
  default:
    return "";
  }
}

std::string DataFormater::formatData(std::vector<StockData> &stockDataArray,
                                     formatingType type) {

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
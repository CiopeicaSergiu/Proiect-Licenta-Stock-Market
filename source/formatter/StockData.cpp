#include "StockData.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

StockData::StockData(const std::string &data) {

  std::vector<std::string> result;
  boost::split(result, data, boost::is_any_of(","));

  if (result.size() != 7) {
    throw std::runtime_error{"Data is missing or not formatted properly!"};
  }

  date = result[0];
  open = result[1];
  low = result[2];
  adj = result[3];
  close = result[4];
  volume = result[5];
}

auto StockData::getElement(dataElement element) const -> std::string {

  switch (element) {
  case dataElement::date:
    return date;
  case dataElement::open:
    return open;
  case dataElement::low:
    return low;
  case dataElement::adj:
    return adj;
  case dataElement::close:
    return close;
  case dataElement::volume:
    return volume;
  default:
    return "";
  }
}
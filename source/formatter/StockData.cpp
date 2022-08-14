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
  high = result[2];
  low = result[3];
  close = result[4];
  adjClose = result[5];
  volume = result[6];
}

auto StockData::getElement(dataElement element) const -> std::string {

  switch (element) {
  case dataElement::date:
    return date;
  case dataElement::open:
    return open;
  case dataElement::high:
    return high;
  case dataElement::low:
    return low;
  case dataElement::close:
    return close;
  case dataElement::adjClose:
    return adjClose;
  case dataElement::volume:
    return volume;
  default:
    return "";
  }
}
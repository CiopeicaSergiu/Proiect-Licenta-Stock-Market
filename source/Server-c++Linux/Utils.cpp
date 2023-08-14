#include "Utils.h"
#include <boost/json/src.hpp>
namespace utils {
namespace Json = boost::json;

Json::value toBoostValue(const std::string &json) {
  try {
    Json::error_code error;
    Json::value jsonValue = Json::parse(json, error);
    return error ? Json::value{} : jsonValue;

  } catch (...) {
  }
  return Json::value{};
}

std::string to_string(const restbed::Bytes &value) {
  return std::string(value.begin(), value.end());
}

} // namespace utils
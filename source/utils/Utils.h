#pragma once
#include <corvusoft/restbed/byte.hpp>
#include <string>
#include <vector>
namespace boost::json {
class value;
}

namespace utils {
namespace Json = boost::json;

Json::value toBoostValue(const std::string &json);
std::string to_string(const restbed::Bytes &value);

} // namespace utils
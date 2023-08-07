#pragma once
#include <fmt/format.h>
#include <string>
#include <unordered_map>
namespace utils {

enum class Operations { insert, update, deletion, select, none };
class SqlGenerator {
public:
  explicit SqlGenerator(const std::string path);

  template <Operations op, typename... Args>
  std::string prepareStatement(Args &&...args) {

    const auto opertionTemplateIt = sqlTemplateStatements.find(op);

    if (opertionTemplateIt == sqlTemplateStatements.end()) {
      return "";
    }

    return fmt::format(opertionTemplateIt->second, args...);
  }

private:
  Operations stringToOperation(const std::string &operationString);
  std::unordered_map<Operations, std::string> sqlTemplateStatements;
};
}; // namespace utils
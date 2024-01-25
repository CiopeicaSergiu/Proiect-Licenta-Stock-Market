#include "SqlGenerator.h"
#include <fstream>

static constexpr char SEPARATOR = ':';

namespace utils {
SqlGenerator::SqlGenerator(const std::string &path) {
  std::ifstream file(path);
  std::string line;

  if (not file.is_open()) {
    throw std::invalid_argument{
        fmt::format("File {} could not be opened.", path)};
  }

  while (std::getline(file, line)) {
    // maybe use boost
    const auto posOfFoundCh = line.find(SEPARATOR);

    if (posOfFoundCh != std::string::npos) {
      sqlTemplateStatements.insert(
          {stringToOperation(line.substr(0, posOfFoundCh)),
           line.substr(posOfFoundCh + 1)});
    }
  }
}
Operations SqlGenerator::stringToOperation(const std::string &operationString) {
  if (operationString == "insert") {
    return Operations::insert;
  } else if (operationString == "deletion") {
    return Operations::deletion;
  } else if (operationString == "update") {
    return Operations::update;
  } else if (operationString == "select") {
    return Operations::select;
  }

  return Operations::none;
}

}; // namespace utils
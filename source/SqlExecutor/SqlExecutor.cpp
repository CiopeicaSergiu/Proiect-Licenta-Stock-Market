#include "SqlExecutor.h"

#include <algorithm>
#include <fmt/format.h>
#include <iterator>

namespace utils {

SubTable::SubTable(const std::vector<std::string> &columnNamePassed) {
  columnsName.reserve(columnNamePassed.size());
  std::copy(columnNamePassed.begin(), columnNamePassed.end(),
            std::back_inserter(columnsName));
}

SqlExecutor::SqlExecutor(const Credentials &credentials,
                         const ConnectionSettings &connectionSettings) {

  driver = get_driver_instance();
  con.reset(driver->connect(fmt::format("{}:{}/{}", connectionSettings.host,
                                        std::to_string(connectionSettings.port),
                                        connectionSettings.database),
                            credentials.username, credentials.password));
  stmt.reset(con->createStatement());
}

// Populeaza un subtable, un subtable este format din toate intrarile selectate
// la executia unui query
void SqlExecutor::executeStatement(const std::string &statement,
                                   SubTable &subTable) {
  // ...
  std::cout << "executeStatement1\n";

  res.reset(stmt->executeQuery(statement));
  std::cout << "executeStatement1\n";
  if (subTable.columnsName.empty()) {
    return;
  }

  while (res->next()) {
    for (const auto &columnName : subTable.columnsName)
      subTable.entries.emplace_back(res->getString(columnName));
  }
}

} // namespace utils
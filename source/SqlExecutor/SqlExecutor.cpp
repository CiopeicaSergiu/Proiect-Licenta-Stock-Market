#include "SqlExecutor.h"

#include <algorithm>
#include <fmt/format.h>
#include <iterator>

namespace utils {

Response::Response(const std::vector<std::string> &columnNamePassed) {}

SqlExecutor::SqlExecutor(const Credentials &credentials,
                         const std::string &host, const unsigned int port) {

  driver.reset(get_driver_instance());
  con.reset(driver->connect(fmt::format("{}:{}", host, std::to_string(port)),
                            credentials.username, credentials.password));
  stmt.reset(con->createStatement());
}

Response
SqlExecutor::executeStatement(const std::string &statement,
                              const std::vector<std::string> &columnNames) {
  // ...
  res.reset(stmt->executeQuery(statement));

  while (res->next()) {
    // You can use either numeric offsets...
    cout << "id = " << res->getInt(1); // getInt(1) returns the first column
    // ... or column names for accessing results.
    // The latter is recommended.
    cout << ", label = '" << res->getString("label") << "'" << endl;
  }
}

} // namespace utils
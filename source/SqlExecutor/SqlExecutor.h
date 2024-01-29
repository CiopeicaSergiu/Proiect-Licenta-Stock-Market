#pragma once
#include <string>
#include <vector>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

namespace stockService {
struct BidAskPrice;
}

namespace utils {
struct Credentials {
  std::string username;
  std::string password;
};
// structura in care facem store la rezultatele unui sql query, primul membru ne
// comunica numele coloanelor
struct SubTable {
  std::vector<std::string> columnsName;
  std::vector<std::string> entries;
  SubTable() = default;
  explicit SubTable(const std::vector<std::string> &columnNamePassed);
};

std::vector<stockService::BidAskPrice> toBidPrices(const SubTable &queryResult);
std::vector<stockService::BidAskPrice> toAskPrices(const SubTable &queryResult);

struct ConnectionSettings {
  std::string host;
  unsigned int port;
  std::string database;
};

class SqlExecutor {
public:
  SqlExecutor(const Credentials &credentials,
              const ConnectionSettings &connectionSettings);

  void executeStatement(const std::string &statement, SubTable &subTable);
  void executeStatement(const std::string &statement);

private:
  sql::Driver *driver = nullptr;
  std::unique_ptr<sql::Connection> con = nullptr;
  std::unique_ptr<sql::Statement> stmt = nullptr;
  std::unique_ptr<sql::ResultSet> res = nullptr;
};
} // namespace utils